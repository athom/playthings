#include<stdio.h>

int n_ones_moutain(int n, int m);

int n_ones_moutain(int n, int m){
    return (1<<(n+m)) - (1<<m);
}

int left_ones(int n){
    int w = sizeof(int) << 3;
    return (-1)<<n;
}



int main(){
    int i1 = n_ones_moutain(3, 0);
    printf("%x\n", i1); // 0x00000007

    i1 = n_ones_moutain(3, 4);
    printf("%x\n", i1); // 0x00000070

    i1 = left_ones(5);
    printf("%x\n", i1); // 0xFFFFFFE0
    return 0;
}
