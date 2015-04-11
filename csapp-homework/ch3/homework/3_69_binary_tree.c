#include <stdio.h>
#include <stdlib.h>

long trace(tree_ptr tp){
    long result = 0;
    while(tp){
        result = tp->left.val;
        tp = tp->left;
    }

    return result;
}

int main(){
    //char buf[8];
    return 0;
}
