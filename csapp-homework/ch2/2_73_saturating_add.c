#include<stdio.h>

// Adding that saturating to TMin or TMax
int saturating_add(int x, int y);

int saturating_add(int x, int y){
    int w = sizeof(int) << 3;
    int mask = (1<<(w-1)); // 10000000 00000000 00000000 00000000
    int sum = x + y;

    int t_min = mask;
    int t_max = ~mask;

    !((!(x & mask)) && (!(y & mask)) && !!(sum & mask)) || (sum = t_max);
    !((!!(x & mask)) && (!!(y & mask)) && !(sum & mask)) || (sum = t_min);

    return sum;
}

int main(){
    int i1 = saturating_add(0x70000000, 0x70000000);
    printf("%x\n", i1); // 0x7FFFFFFF

    i1 = saturating_add(0x80000001, 0x80000010);
    printf("%x\n", i1); // 0x80000000
    return 0;
}
