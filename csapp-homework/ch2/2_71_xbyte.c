#include<stdio.h>

typedef unsigned packed_t;
// Extract byte from word.
// Return as signed integer;
int xbyte(packed_t x, int n);

int xbyte(packed_t x, int n){
    int w = sizeof(packed_t) << 3;
    int nb = n << 3;
    int left_msot = x << (w-nb-8);
    return left_msot >> (w-8);
}

int main(){
    int i1 = xbyte(0x12345678, 0);
    printf("%x\n", i1); // 78
    i1 = xbyte(0x12345678, 1);
    printf("%x\n", i1); // 56
    i1 = xbyte(0x12345678, 2);
    printf("%x\n", i1); // 34
    i1 = xbyte(0x12345678, 3);
    printf("%x\n", i1); // 12

    i1 = xbyte(0x12345680, 0);
    printf("%x\n", i1); // 80
    printf("%d\n", i1); // -128

    i1 = xbyte(0x12805623, 2);
    printf("%x\n", i1); // 80
    printf("%d\n", i1); // -128
    printf("%d\n", 0xffffff80); // -128
    return 0;
}
