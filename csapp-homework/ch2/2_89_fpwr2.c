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
    unsigned exp, frac;
    unsigned u;
    if(x < -149){
        exp = 0;
        frac = 0;
    }else if(x < -126){
        exp = 0;
        frac = 1 << (23+(x+126));
    }else if(x < 127){
        exp = 127 + x;
        frac = 0;
    }else{
        exp = 0xFF;
        frac = 0;
    }

    u = exp << 23 | frac;
    return u2f(u);
}

int main(){
    float f;

    f = fpwr2(0);
    printf("%f\n", f); // 0
    f = fpwr2(1);
    printf("%f\n", f); // 0
    f = fpwr2(2);
    printf("%f\n", f); // 0
    f = fpwr2(10);
    printf("%f\n", f); // 0
    f = fpwr2(16);
    printf("%f\n", f); // 0
    printf("\n");


    f = fpwr2(-1);
    printf("%f\n", f); // 0
    f = fpwr2(-2);
    printf("%f\n", f); // 0
    f = fpwr2(-3);
    printf("%f\n", f); // 0
    f = fpwr2(-4);
    printf("%f\n", f); // 0
    f = fpwr2(-5);
    printf("%f\n", f); // 0
    printf("\n");

    f = fpwr2(-150);
    printf("%f\n", f); // float 0
    f = fpwr2(-149);
    printf("%f\n", f); // float 0
    f = fpwr2(-148);
    printf("%f\n", f); // float 0
    f = fpwr2(-147);
    printf("%f\n", f); // float 0
    f = fpwr2(-146);
    printf("%f\n", f); // float 0
    printf("\n");


    f = fpwr2(-137);
    printf("%f\n", f); // float 0
    f = fpwr2(-128);
    printf("%f\n", f); // float 0
    f = fpwr2(-129);
    printf("%f\n", f); // float 0
    f = fpwr2(-130);
    printf("%f\n", f); // float 0

    printf("\n");
    f = fpwr2(127);
    printf("%f\n", f); // float 0

    return 0;
}
