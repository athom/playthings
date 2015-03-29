#include<stdio.h>

// Do rotating right shift.
// Assume 0 <= n < w
// Example when x = 0x12345678 and w = 32
//      n = 4 ->    0x81234567
//      n = 20->    0x45678123
int rotate_right(unsigned x, int n);

int rotate_right(unsigned x, int n){
    int w = sizeof(int) << 3;
    int mask = (1 << n) - 1;

    int hight_bits = (x & mask) << (w - n);
    int low_bits = x >> n;

    return hight_bits | low_bits;
}

int main(){
    int i1 = rotate_right(0x12345678, 4);
    printf("%x\n", i1);

    // NOTE speical case
    i1 = rotate_right(0x12345678, 20);
    printf("%x\n", i1);

    i1 = rotate_right(0x12345678, 32);
    printf("%x\n", i1);

    i1 = rotate_right(0x12345678, 0);
    printf("%x\n", i1);
    return 0;
}
