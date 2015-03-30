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

int is_non_standard(float_bits f){
    float_bits exp = (f >> 23)&0xFF;
    return !(exp);
}

int is_infinity(float_bits f){
    float_bits frac = f & 0x7FFFFF;
    float_bits exp = (f >> 23)&0xFF;
    return (!(exp^0xFF) && !frac);
}


float_bits float_twice(float_bits f){
    if(is_nan(f)){
        return f;
    }

    if(is_infinity(f)){
        return f;
    }

    if(is_non_standard(f)){
        float_bits size = (f >> 31) <<31;
        float_bits exp = (f >> 23)&0xFF;
        float_bits frac = f & 0x7FFFFF;
        float_bits frac_mask = frac << 1;
        if(!frac){
            exp += 1;
        }
        float_bits new_exp = exp<< 23;
        return (size | new_exp | frac_mask);
    }


    float_bits size = (f >> 31) <<31;
    float_bits exp = (f >> 23)&0xFF;
    float_bits new_exp = (exp + 1) << 23;
    return (size | new_exp | (f & 0x7FFFFF));
}

int main(){
    float_bits f;
    float_bits u;

    // pi
    u = 0x40490FDB;
    f = float_twice(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));

    // -pi
    u = 0xC0490FDB;
    f = float_twice(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));

    // + non standard
    u = 0x00490FDB;
    f = float_twice(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);

    // - non standard
    u = 0x80490FDB;
    f = float_twice(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);

    // Nan
    u = 0xFF890FDB;
    f = float_twice(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);

    // Nan
    u = 0x7F890FDB;
    f = float_twice(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);


    // + Infinity
    u = 0x7F800000;
    f = float_twice(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);

    // - Infinity
    u = 0xFF800000;
    f = float_twice(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);
    return 0;
}
