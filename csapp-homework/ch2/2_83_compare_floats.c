#include<stdio.h>

unsigned int f2u(float x){
    union {
        float f; unsigned u;
    } a;
    a.f = x;
    return a.u;
}

int float_age(float x, float y){
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    // Get the sign bits
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    // using only ux, uy, sx, sy
    return (
                (!(sx^sy))
                    &&
                (
                    (
                        (!sx) && ((ux>uy))
                    )
                    ||
                    (
                        (!!sx) && (!!(ux<uy))
                    )
                )
            )
            ||
            (
                 (sx^sy) && !sx
            );
}

int main(){
    int i1;

    i1 = float_age(3.15, 3.14);
    printf("%x\n", i1); // 1

    i1 = float_age(3.14, 3.15);
    printf("%x\n", i1); // 0

    i1 = float_age(-3.15, -3.14);
    printf("%x\n", i1); // 0

    i1 = float_age(-3.14, -3.15);
    printf("%x\n", i1); // 1

    i1 = float_age(-3.14, 3.15);
    printf("%x\n", i1); // 0
    i1 = float_age(3.14, -3.15);
    printf("%x\n", i1); // 1
    i1 = float_age(-3.15, 3.14);
    printf("%x\n", i1); // 0
    i1 = float_age(3.15, -3.14);
    printf("%x\n", i1); // 1
    return 0;
}
