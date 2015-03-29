#include<stdio.h>

// Devide by power of 2, Assume 0 <= k < w-1
int divide_power2(int x, int k);

int divide_power2(int x, int k){
    int w = sizeof(int) << 3;
    int mask = 1 << (w-1);
    int res = x >> k;
    int offset = (1<<k) -1;
    (!(x & mask)) || (res = ((x + offset) >> k));
    return res;
}

int main(){
    int i1 = divide_power2(-6, 1);
    printf("%d\n", i1); // -3;

    i1 = divide_power2(-7, 1);
    printf("%d\n", i1); // -3;

    i1 = divide_power2(7, 1);
    printf("%d\n", i1); // 3;

    i1 = divide_power2(6, 1);
    printf("%d\n", i1); // 3;

    i1 = divide_power2(7, 2);
    printf("%d\n", i1); // 1;

    i1 = divide_power2(6, 2);
    printf("%d\n", i1); // 1;
    return 0;
}
