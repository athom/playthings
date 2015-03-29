#include<stdio.h>

int leftmost_one(unsigned x);

int leftmost_one(unsigned x){
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;

    return (x ^ (x>>1));
}

int main(){
    int i1 = leftmost_one(0xFF00);
    printf("%x\n", i1);

    int i2 = leftmost_one(0x6600);
    printf("%x\n", i2);
    return 0;
}
