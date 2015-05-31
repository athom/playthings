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


#define USE_NEXT_SEARCH 1

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
static char* mm_next_visit_ptr;

static int mm_check(char, void*, size_t);
static size_t mm_new_size(size_t size);

/*
 * coalesce - merge free memory
 */
static void* coalesce(char* bp)
{
    size_t prev_alloc = GET_ALLOC(bp-DSIZE);
    size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));

    if (prev_alloc && next_alloc)
    {
        return bp;
    }

    if (!prev_alloc && next_alloc)
    {

#ifdef  USE_NEXT_SEARCH
        if (bp == mm_next_visit_ptr)
        {
            mm_next_visit_ptr = PREV_BLKP(bp);
        }
#endif

        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        PUT(FTRP(bp),               PACK(size,0));
        bp = PREV_BLKP(bp);
        PUT(HDRP(bp),    PACK(size,0));
        return bp;
    }

    if (prev_alloc && !next_alloc)
    {
#ifdef  USE_NEXT_SEARCH
        if (NEXT_BLKP(bp) == mm_next_visit_ptr)
        {
            mm_next_visit_ptr = bp;
        }
#endif

        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        PUT(HDRP(bp),   PACK(size,0));
        PUT(FTRP(bp),   PACK(size,0));
        return bp;

    }

    if (!prev_alloc && !next_alloc)
    {
#ifdef  USE_NEXT_SEARCH
        if (NEXT_BLKP(bp) == mm_next_visit_ptr || bp == mm_next_visit_ptr)
        {
            mm_next_visit_ptr = PREV_BLKP(bp);
        }
#endif

        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        //size += GET_SIZE(FTRP(NEXT_BLKP(bp)));
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

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));

    //mm_check('c', bp, 1);
    bp = coalesce(bp);
    //mm_check('C', bp, 1);
    return bp;
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

    //mm_check('b', mm_heap_start, 1);
    if (extend_heap(CHUNKSIZE/WSIZE) == NULL)
    {
        return -1;
    }
    //mm_check('i', mm_heap_start, 1);


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
    void* p;
#ifdef  USE_NEXT_SEARCH
    if (mm_next_visit_ptr != NULL)
    {
        p = mm_next_visit_ptr;
        mm_next_visit_ptr = NULL;
        if (!GET_ALLOC(HDRP(p)) && GET_SIZE(HDRP(p)) >= size)
        {
            return p;
        }
    }
#endif

    p = mm_heap_start;
    for (; !is_epilogue(p); p = NEXT_BLKP(p))
    {
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


    }else
    {
        PUT(HDRP(p), PACK(oldsize, 1));
        PUT(FTRP(p), PACK(oldsize, 1));
    }

#ifdef  USE_NEXT_SEARCH
    mm_next_visit_ptr = NEXT_BLKP(p);
#endif
}
/*
 * mm_new_size - Cauculate new block size from the size
 */
static size_t mm_new_size(size_t size)
{
    if (size <= DSIZE)
    {
        return 2*DSIZE;
    }
    return ALIGN(size + SIZE_T_SIZE);
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

    newsize = mm_new_size(size);

    extendsize = MAX(newsize, CHUNKSIZE);

    bp = find_fit(newsize);
    if (bp != NULL)
    {
        mm_check('a', bp, 1);
        place(bp, newsize);
        //mm_check('A', bp, 1);
        return bp;
    }



    bp = extend_heap(extendsize/WSIZE);
    if (bp == NULL)
    {
       return NULL;
    }

    //mm_check('e', bp, 1);
    place(bp, newsize);
    //mm_check('E', bp, 1);
    return bp;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr)
{
    //mm_check('f', ptr, 1);
    size_t size = GET_SIZE(HDRP(ptr));
    PUT(HDRP(ptr), PACK(size, 0));
    PUT(FTRP(ptr), PACK(size, 0));
    coalesce(ptr);
    //mm_check('F', ptr, 1);
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

    size_t newsize = mm_new_size(size);
    size_t oldsize = GET_SIZE(HDRP(oldptr));
    if (newsize <= oldsize)
    {
        place(oldptr, newsize);
        return oldptr;
    }

    newptr = mm_malloc(size);
    if (newptr == NULL)
      return NULL;

    size_t copysize = oldsize - WSIZE;
    memcpy(newptr, oldptr, copysize);
    mm_free(oldptr);
    return newptr;
}


/*
 * mm_check - Implement the heap checker for debug
 */
static int mm_check(char action, void* p, size_t size)
{
    return 0;
    void* prev_p = PREV_BLKP(p);
    void* next_p = NEXT_BLKP(p);

    if (mm_next_visit_ptr != NULL)
    {
#ifdef  USE_NEXT_SEARCH
        void* mp = mm_next_visit_ptr;
        printf("%c    prev_p:%-8p %-8u %-2d    cur_p:%-8p %-8u %-2d next_p:%-8p %-8u %-2d mm_p:%-8p %-8u %-2d\n",
                action,
                prev_p, GET_SIZE(HDRP(prev_p)), GET_ALLOC(HDRP(prev_p)),
                p, GET_SIZE(HDRP(p)), GET_ALLOC(HDRP(p)),
                next_p, GET_SIZE(HDRP(next_p)), GET_ALLOC(HDRP(next_p)),
                mp, GET_SIZE(HDRP(mp)), GET_ALLOC(HDRP(mp)));
#endif
    }else{
        printf("%c    prev_p:%-8p %-8u %-2d    cur_p:%-8p %-8u %-2d next_p:%-8p %-8u %-2d \n",
                action,
                prev_p, GET_SIZE(HDRP(prev_p)), GET_ALLOC(HDRP(prev_p)),
                p, GET_SIZE(HDRP(p)), GET_ALLOC(HDRP(p)),
                next_p, GET_SIZE(HDRP(next_p)), GET_ALLOC(HDRP(next_p)));
    }

    return 0;
}
