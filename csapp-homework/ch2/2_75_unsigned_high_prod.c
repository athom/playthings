#include<stdio.h>

int unsigned_high_prod(int x, int y);

int unsigned_high_prod(int x, int y){
    int w = sizeof(int) << 3;
    int leftmost_bit_x = x >> (w-1) & 1;
    int leftmost_bit_y = y >> (w-1) & 1;
    return (~leftmost_bit_x+1)&y + (~leftmost_bit_y+1)&x + (!!(leftmost_bit_x&leftmost_bit_y)) << (w -1);
}

int main(){
    return 0;
}
