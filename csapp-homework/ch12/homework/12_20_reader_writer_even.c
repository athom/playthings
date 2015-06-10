#include "csapp.h"

int reader_count;
int writer_count;
sem_t reader_count_mutex;
sem_t content_mutex;
sem_t read_write_gap;

void reading(){
    while(1){
        P(&read_write_gap);
        P(&reader_count_mutex);
        reader_count++;
        if (reader_count == 1)
        {
            P(&content_mutex);
        }
        V(&reader_count_mutex);
        V(&read_write_gap);

        printf("Do some reading jobs \n");

        P(&reader_count_mutex);
        reader_count--;
        if (read_count == 0)
        {
            V(&content_mutex);
        }
        V(&read_count_mutex);

    }
}

void writing(){
    while(1){
        P(&read_write_gap);
        P(&content_mutex);

        printf("Do some writing jobs \n");

        V(&content_mutex);
        V(&read_write_gap);
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
