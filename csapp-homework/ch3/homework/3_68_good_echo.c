#include <stdio.h>
#include <stdlib.h>

char* gets(char* s){
    int c;
    char* dest = s;
    int gotchar = 0;
    while((c = getchar()) != '\n' && c != EOF){
        *dest ++ = c;
        gotchar = 1;
    }

    *dest++ = '\0';
    if(c == EOF && !gotchar){
        return NULL;
    }
    return s;
}

int main(){
    //char buf[8];
    char* buf = (char *)malloc(1000 * sizeof(char));
    gets(buf);
    puts(buf);
    free(buf);
    return 0;
}
