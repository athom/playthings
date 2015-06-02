#include<stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage ./hex2dd xxxxx\n");
        return -1;
    }

    unsigned int ip = (unsigned int)(strtol(argv[1], NULL, 16));
    char ip_a[14];
    sprintf(ip_a, "%d.%d.%d.%d", ip>>24, ip>>16 & 0xFF, ip>>8 & 0xFF, ip & 0xFF);

    printf("ip addr is: %s      ip is: %s\n", argv[1], ip_a);
    return 0;
}
