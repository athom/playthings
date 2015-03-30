#include<stdio.h>

float u2f(unsigned x){
    union {
        unsigned u;
        float f;
    } a;
    a.u = x;
    return a.f;
}

float fpwr2(int x){
    return 0.0;
}

int main(){
    float f;
    unsigned x = 0x40490FDB;
    f = u2f(x);
    printf("%f", f);

    return 0;
}
