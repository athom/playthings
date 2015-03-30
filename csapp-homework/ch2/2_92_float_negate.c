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


//float_bits float_negate(float_bits f){
    //if(is_nan(f)){
        //return f;
    //}

    //float_bits sz_mask = (((f >> 31)^0x1) << 31);

    //return ((f & 0x7FFFFFFF) | sz_mask);
//}

float_bits float_negate(float_bits f){
    if(is_nan(f)){
        return f;
    }

    return (f ^ 0x80000000);
}

int main(){
    float_bits f;
    float_bits u;

    // pi
    u = 0x40490FDB;
    f = float_negate(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));

    // -pi
    u = 0xC0490FDB;
    f = float_negate(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));

    // Nan
    u = 0xFF890FDB;
    f = float_negate(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);

    // Nan
    u = 0x7F890FDB;
    f = float_negate(u);
    printf("%f\n", u2f(u));
    printf("%f\n", u2f(f));
    printf("%x\n", u);
    printf("%x\n", f);

    return 0;
}
