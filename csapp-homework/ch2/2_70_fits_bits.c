#include<stdio.h>

// Return 1 when x can be represented as an n-bit, 2's complement number;
// 0 otherwise.
// Assume 1 <= n <= w
int fits_bits(int x, int n);

int fits_bits(int x, int n){
    int w = sizeof(int) << 3;
    int mask = 0;
    (n == w) || (mask = ~((1 << n) - 1));
    return !(x & mask);
}

int main(){
    int i1 = fits_bits(0x12345678, 4);
    printf("%x\n", i1); // 0
    i1 = fits_bits(0x00000008, 4);
    printf("%x\n", i1); // 1

    // NOTE speical case
    i1 = fits_bits(0x00345678, 24);
    printf("%x\n", i1); // 1
    i1 = fits_bits(0x01345678, 24);
    printf("%x\n", i1); // 0

    i1 = fits_bits(0x12345678, 32);
    printf("%x\n", i1); // 1

    i1 = fits_bits(0x00000001, 1);
    printf("%x\n", i1); // 1
    i1 = fits_bits(0x00000002, 1);
    printf("%x\n", i1); // 0
    i1 = fits_bits(0x12345678, 1);
    printf("%x\n", i1); // 0
    return 0;
}
