#include<stdio.h>

int any_even_one(unsigned x);

int any_even_one(unsigned x){
    return !!(x & 0xAAAA);
}

int main(){
    int i1 = any_even_one(4);
    printf("%d\n", i1);

    return 0;
}
