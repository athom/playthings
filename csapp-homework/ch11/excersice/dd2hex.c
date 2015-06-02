#include<stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage ./dd2hex xxxxx\n");
        return -1;
    }

    char a[4][4];
    char*p = argv[1];

    int i = 0;
    int j = 0;
    while(*p){
        if (*p != '.')
        {
            a[i][j] = *p;
            j++;
        }else{
            i++;
            j=0;
        }
        p++;
    }

    int ip1 = atoi(a[0]);
    int ip2 = atoi(a[1]);
    int ip3 = atoi(a[2]);
    int ip4 = atoi(a[3]);

    unsigned ip = (ip1 << 24) + (ip2 << 16) + (ip3 << 8) + ip4;

    printf("ip addr is: %s    int ip is: %x\n", argv[1], ip);
    return 0;
}
