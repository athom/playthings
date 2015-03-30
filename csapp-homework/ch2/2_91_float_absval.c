#include<stdio.h>

typedef unsigned float_bits;

float u2f(unsigned x){
    union {
        unsigned u;
        float f;
    } a;
    a.u = x;
    return a.f;
}

int is_nan(float_bits f){
    float_bits frac = f & 0x7FFFFF;
    float_bits exp = (f >> 23)&0xFF;
    return (!(exp^0xFF) && frac);
}

float_bits float_absval(float_bits f){
    if(is_nan(f)){
        return f;
    }

    int w = sizeof(float_bits) << 3;
    return f & ~(1<<(w-1));
}

int main(){
    float_bits f;

    // pi
    float_bits u = 0x40490FDB;
    f = float_absval(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));

    // -pi
    u = 0xC0490FDB;
    f = float_absval(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));


    // Nan
    u = 0xFF890FDB;
    f = float_absval(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);

    // Nan
    u = 0x7F890FDB;
    f = float_absval(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);

    return 0;
}
