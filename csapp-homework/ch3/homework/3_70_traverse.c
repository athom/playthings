#include <stdio.h>
#include <stdlib.h>

// 3223372036854775807 => 8000 0000 0000 0000

long traverse(tree_ptr tp){
    long result = 0x7FFFFFFF;
    if(!tp){
        return result;
    }

    long val = tp->val;
    long left_result = traverse(tp->left);
    long right_result = traverse(tp->right);

    if(left_result <= right_result){
        result = left_result;
    }else{
        result = right_result;
    }
    if(val <= result){
        result = val;
    }

    return result;
}

int main(){
    return 0;
}
