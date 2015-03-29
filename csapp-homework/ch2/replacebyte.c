#include<stdio.h>

unsigned replace_byte(unsigned x, unsigned char b, int i);

//unsigned replace_byte(unsigned x, unsigned char b, int i){
    //// example if i = 1, then mask == 0xFFFF00FF;
    //unsigned int mask = ~(0xFF << (i*8));

    //// new_x will be something like  0xXXXX00XX;
    //// X stands for the original value;
    //unsigned int new_x = x & mask;

    //// example: if i = 1, b = 0xCC; then set = 0x0000CC00;
    //unsigned int set = unsigned(b) << (i*8);
    //return new_x | set;
//}

unsigned replace_byte(unsigned x, unsigned char b, int i){
    return (~(0xFF << (i*8)) & x) | (b << (i*8));
}

int main(){

    unsigned a = 0x12345678;
    char b = 0xAB;
    printf("%x\n", a);

    unsigned out = replace_byte(a, b, 0);
    printf("%x\n", out);

    unsigned out2 = replace_byte(a, b, 1);
    printf("%x\n", out2);

    unsigned out3 = replace_byte(a, b, 2);
    printf("%x\n", out3);

    unsigned out4 = replace_byte(a, b, 3);
    printf("%x\n", out4);

    return 0;
}
