#include<stdio.h>

int mul5div8(int x);

// solution without considering overflow
int mul5div8_with_ovf(int x){
    int w = sizeof(int) << 3;
    int mask = 1 << (w-1);
    int bias = (1<<3) -1;

    int mul5 = (x<<2)+x;
    int res = mul5 >> 3;
    (!(x & mask)) || (res = ((mul5 + bias) >> 3));

    return res;
}

// avoid overflow solution , seems not work, why?
int mul5div8_no_ovf(int x){
    return (x >> 1) + (x+bias >> 3);
}

int mul5div8(int x){
    return mul5div8_with_ovf(x);
}

int main(){
    int i1 = mul5div8(-6);
    printf("%d\n", i1); // -3;

    i1 = mul5div8(7);
    printf("%d\n", i1); // 4;
    return 0;
}
