#include "csapp.h"

int read_count;
sem_t read_count_mutex;
sem_t content_mutex;

void reading(){
    while(1){
        P(&read_count_mutex);
        read_count++;
        if (read_count == 1)
        {
            P(&content_mutex);
        }
        V(&read_count_mutex);

        printf("Do some reading jobs \n");

        P(&read_count_mutex);
        read_count--;
        if (read_count == 0)
        {
            V(&content_mutex);
        }
        V(&read_count_mutex);

    }
}

void writing(){
    while(1){
        P(&content_mutex);

        printf("Do some writing jobs \n");

        V(&content_mutex);
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
