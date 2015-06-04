#include<stdio.h>
#include <pthread.h>

void* handler(void*);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
       printf("usage: ./xxxx n\n");
       return -1;
    }

    int n = atoi(argv[1]);
    int i = 0;

    pthread_t tid[n];
    for (i = 0; i < n; ++i)
    {
        pthread_create(&tid[i], NULL, handler, NULL);
    }

    for (i = 0; i < n; ++i)
    {
        pthread_join(tid[i], NULL);
    }
    return 0;
}

void* handler(void* vargp)
{
    printf("hello kitty\n");
    return NULL;
}
