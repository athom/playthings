#include<stdio.h>

int divide_power2(int x, int k);
int five_eights(int x);

int divide_power2(int x, int k){
    int w = sizeof(int) << 3;
    int mask = 1 << (w-1);
    int res = x >> k;
    int offset = (1<<k) -1;
    (!(x & mask)) || (res = ((x + offset) >> k));
    return res;
}

int five_eights(int x){
    int base =  divide_power2(x,1) + divide_power2(x,3);
    int extra = 0;
    (x^0x5) || (extra = 1);
    (x^0x7) || (extra = 1);
    (-x^0x5) || (extra = -1);
    (-x^0x7) || (extra = -1);
    return base + extra;
}



int main(){
    int i1 = five_eights(-6);
    printf("%d\n", i1); // -3;

    i1 = five_eights(7);
    printf("%d\n", i1); // 4;

    i1 = five_eights(-7);
    printf("%d\n", i1); // -4;
    return 0;
}
