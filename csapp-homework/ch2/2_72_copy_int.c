#include<stdio.h>
#include<string.h>

typedef unsigned packed_t;
// Extract byte from word.
// Return as signed integer;
void copy_int(int val, void* buf, int maxbytes);

void copy_int(int val, void* buf, int maxbytes){
    int sz = sizeof(val);
    if(maxbytes >= sz){
        memcpy(buf, (void*)&val, sz);
    }
}

int main(){
    return 0;
}
