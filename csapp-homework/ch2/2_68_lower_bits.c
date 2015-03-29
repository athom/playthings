#include<stdio.h>

int lower_bits(int x, int n);

int lower_bits(int x, int n){
    // w is 32 bits
    int w = sizeof(int) << 3;

    int mask = -1;
    (n == w) || (mask = (1 << n) -1);
    return x & mask;
}

int main(){
    int i1 = lower_bits(0x12345678, 8);
    printf("%x\n", i1);

    // NOTE speical case
    i1 = lower_bits(0x12345678, 32);
    printf("%x\n", i1);
    return 0;
}
