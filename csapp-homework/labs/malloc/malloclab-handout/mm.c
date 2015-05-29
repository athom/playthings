/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 *
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "Apollo",
    /* First member's full name */
    "Yeer Kunst",
    /* First member's email address */
    "yeerkunth@gmail.com",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)


#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))


/* base macro for header computing */
#define WSIZE 4
#define DSIZE 8
#define CHUNKSIZE (1<<12) // 4MB

#define MAX(x, y) ((x) > (y) ? (x): (y))

#define PACK(size, alloc) ((size) | (alloc))

#define GET(p) (*(unsigned int*)(p))
#define PUT(p, val) (*(unsigned int*)(p) = (val))

#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

#define HDRP(bp) ((char*)(bp) - WSIZE)
#define FTRP(bp) ((char*)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

#define NEXT_BLKP(bp) ((char*)(bp) + GET_SIZE(HDRP(bp)))
#define PREV_BLKP(bp) ((char*)(bp) - GET_SIZE(((char*)(bp) - DSIZE)))

/* vars and funcs */
static char* mm_heap_start;
static char* mm_heap_end;

static int mm_check(char, void*, size_t);

/*
 * coalesce - merge free memory
 */
static void* coalesce(char* bp)
{
    //size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
    size_t prev_alloc = GET_ALLOC(bp-DSIZE);
    size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));

    if (prev_alloc && next_alloc)
    {
        return bp;
    }

    if (!prev_alloc && next_alloc)
    {
        void* prev_blk = PREV_BLKP(bp);
        void* prev_blk_head = HDRP(prev_blk);
        unsigned int raw = *((unsigned int*)prev_blk_head);
        size_t prev_size = GET_SIZE(HDRP(PREV_BLKP(bp)));
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        PUT(FTRP(bp),               PACK(size,0));
        PUT(HDRP(PREV_BLKP(bp)),    PACK(size,0));
        bp = PREV_BLKP(bp);
        //printf("coalesce ptr: %x     size: %u   pre size:%u prev block: %x head:%x raw:%x\n", bp, size, prev_size, prev_blk, prev_blk_head, raw);
        return bp;
    }

    if (prev_alloc && !next_alloc)
    {
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        PUT(HDRP(bp),               PACK(size,0));
        PUT(FTRP(bp),    PACK(size,0));
        // NOTE should not use the below code
        //PUT(FTRP(NEXT_BLKP(bp)),    PACK(size,0));
        return bp;

    }

    if (!prev_alloc && !next_alloc)
    {
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        //size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        size += GET_SIZE(FTRP(NEXT_BLKP(bp)));

        PUT(HDRP(PREV_BLKP(bp)),    PACK(size,0));
        PUT(FTRP(NEXT_BLKP(bp)),    PACK(size,0));
        bp = PREV_BLKP(bp);
        return bp;
    }

    return bp;
}

/*
 * extend_heap - extend heap from OS
 */
static void* extend_heap(size_t words)
{
    char* bp;
    size_t size;

    size = (words % 2) ? ((words + 1) * WSIZE) : (words * WSIZE);
    if ((long)(bp = mem_sbrk(size)) == -1)
    {
        return NULL;
    }

    mm_heap_end = HDRP(NEXT_BLKP(bp));
    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));

    //printf("old p:  %x\n", bp);
    bp = coalesce(bp);
    //printf("new p:  %x\n", bp);
    return bp;
    //return coalesce(bp);
}


/*
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
    if ((mm_heap_start = mem_sbrk(4*WSIZE)) == (void*)-1)
    {
        return -1;
    }

    void* bp = mm_heap_start;
    PUT(bp, 0);
    PUT(bp+(1*WSIZE), PACK(DSIZE, 1));
    PUT(bp+(2*WSIZE), PACK(DSIZE, 1));
    PUT(bp+(3*WSIZE), PACK(0, 1));
    mm_heap_start += 4*WSIZE;

    mm_check('b', mm_heap_start, 1);
    if (extend_heap(CHUNKSIZE/WSIZE) == NULL)
    {
        return -1;
    }
    mm_check('i', mm_heap_start, 1);


    return 0;
}

/*
 *  is_epilogue detect the current poiter is located in the epiloque block
 */
static int is_epilogue(char* p)
{
    if (GET_SIZE(HDRP(p)) == 0)
    {
        return 1;
    }
    return 0;
}

/*
 *  find_fit search the proper block for alloc
 */
static void *find_fit(size_t size){
    void* p = mm_heap_start;
    for (; !is_epilogue(p); p = NEXT_BLKP(p))
    {
            //printf("bp:%x   alloc:%d  head size:%u    size:%u \n", p, GET_ALLOC(HDRP(p)), GET_SIZE(HDRP(p)), size );
        if (!GET_ALLOC(HDRP(p)) && GET_SIZE(HDRP(p)) >= size)
        {
            return p;
        }
    }

    return NULL;
}

static void place(void* p, size_t size)
{
    size_t oldsize = GET_SIZE(HDRP(p));
    size_t rest_size = oldsize - size;
    if (rest_size >= 2*DSIZE)
    {
        PUT(HDRP(p), PACK(size, 1));
        PUT(FTRP(p), PACK(size, 1));

        char* rest_blk = NEXT_BLKP(p);
        PUT(HDRP(rest_blk), PACK(rest_size, 0));
        PUT(FTRP(rest_blk), PACK(rest_size, 0));

        //printf("ptr: %x     rest size: %u       %u\n", rest_blk, rest_size, GET_SIZE(HDRP(NEXT_BLKP(p))));

    }else
    {
        PUT(HDRP(p), PACK(oldsize, 1));
        PUT(FTRP(p), PACK(oldsize, 1));
    }
}

/*
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
    size_t newsize;
    size_t extendsize;
    char* bp;

    if (size == 0)
    {
        return NULL;
    }

    if (size <= DSIZE)
    {
        newsize = 2*DSIZE;
    }else
    {
        //newsize = DSIZE*((size + (DSIZE) + DSIZE -1)/DSIZE);
        newsize = ALIGN(size + SIZE_T_SIZE);
    }

    extendsize = MAX(newsize, CHUNKSIZE);
    //printf("newsize: %u,    extendsize: %u      chunksize: %u \n", newsize, extendsize, CHUNKSIZE);

    bp = find_fit(newsize);
    if (bp != NULL)
    {
        mm_check('a', bp, 1);
        place(bp, newsize);
        mm_check('A', bp, 1);
        return bp;
    }



    bp = extend_heap(extendsize/WSIZE);
    if (bp == NULL)
    {
       return NULL;
    }

    mm_check('e', bp, 1);
    place(bp, newsize);
    mm_check('E', bp, 1);
    return bp;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr)
{
    size_t size = GET_SIZE(HDRP(ptr));
    PUT(HDRP(ptr), PACK(size, 0));
    PUT(FTRP(ptr), PACK(size, 0));
    mm_check('f', ptr, 1);
    coalesce(ptr);
    mm_check('F', ptr, 1);
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
    {
        return mm_malloc(size);
    }
    if (size == 0)
    {
        mm_free(ptr);
        return  NULL;
    }

    void *oldptr = ptr;
    void *newptr;
    size_t copySize;

    newptr = mm_malloc(size);
    if (newptr == NULL)
      return NULL;
    copySize = GET_SIZE(HDRP(oldptr)) - WSIZE;
    //copySize = *(size_t *)((char *)oldptr - SIZE_T_SIZE);
    if (size < copySize)
      copySize = size;
    memcpy(newptr, oldptr, copySize);
    mm_free(oldptr);
    return newptr;
}

//void *mm_realloc(void *ptr, size_t size)
//{
    //void *oldptr = ptr;
    //void *newptr;
    //size_t copySize;

    //newptr = mm_malloc(size);
    //if (newptr == NULL)
      //return NULL;
    //copySize = *(size_t *)((char *)oldptr - SIZE_T_SIZE);
    //if (size < copySize)
      //copySize = size;
    //memcpy(newptr, oldptr, copySize);
    //mm_free(oldptr);
    //return newptr;
//}


/*
 * mm_check - Implement the heap checker for debug
 */
static int mm_check(char action, void* p, size_t size)
{
    return 0;

    unsigned int head;
    head = *((unsigned int*)(HDRP(p)));
    size_t sz = GET_SIZE(HDRP(p));
    int is_alloc = GET_ALLOC(HDRP(p));

    void* last_block = mem_heap_hi()-3;
    //void* last_block = mm_heap_end;
    unsigned int raw_header = *((unsigned int*)HDRP(last_block));
    size_t last_sz = GET_SIZE(HDRP(last_block));

    //printf("current pointer: %x\n", p);
    //printf("current head: %x\n", head);
    //printf("%c    ptr:%-8x    size:%-8u     %-8x  last:%-8x     alloc:%-2d \n", action, p, sz, sz, last_block, is_alloc);
    printf("%c    %-8x    %-8u     %-8x  %-8x %-8x  %-8u     %-2d \n", action, p, sz, sz, last_block, raw_header, last_sz, is_alloc);

    return 0;
}









