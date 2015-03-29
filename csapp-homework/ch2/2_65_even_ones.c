#include<stdio.h>

int even_ones(unsigned x);

int even_ones(unsigned x){
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return !(x&1);
}

int main(){
    int i1 = even_ones(4);
    printf("%d\n", i1);

    int i2 = even_ones(3);
    printf("%d\n", i2);

    int i3 = even_ones(7);
    printf("%d\n", i3);

    return 0;
}
