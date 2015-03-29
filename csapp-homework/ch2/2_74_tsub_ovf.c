#include<stdio.h>

// Determine whether subtracting arguments will cause overflow
int tsub_ovf(int x, int y);

int tsub_ovf(int x, int y){
    int sum = x - y;
    return (x > 0) && (y < 0) && (sum <0) || (x < 0) && (y > 0) && (sum > 0);
}

int main(){
    int i1 = tsub_ovf(0x7FFFFFFF, 0x80000001);
    printf("%x\n", i1); // 0x7FFFFFFF

    i1 = tsub_ovf(0x80000001, 0x7FFFFFFF);
    printf("%x\n", i1); // 0x80000000
    return 0;
}
