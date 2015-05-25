#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

unsigned int snooze(unsigned int secs){
    unsigned int rc = sleep(secs);
    printf("Sleep for %u of %u secs.\n", secs - rc, secs);
    return rc;
}

void handler(int sig){
    printf("\ncalling sig handler for %u. \n", sig);
    //exit(0); // Don't exit, or else it wont return to sleep process
}


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments.\n");
        return -1;
    }

    int sec = atoi(argv[1]);
    printf("input sec: %d\n", sec);

    if (signal(SIGINT, handler) == SIG_ERR)
    {
        printf("signal error\n");
        //exit(-1);
    }

    snooze(sec);
    return 0;
}
