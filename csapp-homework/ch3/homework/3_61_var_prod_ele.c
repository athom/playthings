int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k){
    int j;
    int result = 0;

    for(j = 0; j < n; j++){
        result += A[i][j] * B[i][j]
    }

    return result;
}

// no registers overflow
int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k){
    int j;
    int result = 0;
    int* Arow = A[i][0];
    int* Bptr = B[0][k];

    for(j = 0; j < n; j++){
        result += A[j] * *Btpr
        Bptr += n;
    }

    return result;
}


// Arow     esi
// Bptr     ecx
// j        edx
// result   ebx
// 4*n      edi
.L30:
    movl (%ecx), %eax                   // get *Bptr
    imull (%esi, %edx, 4), %eax         // Arow[j]
    addl %eax, %ebx                     // add to result
    addl $1, %edx                       // increase j
    addl %edi, %ecx                     // Add 4*n to Bptr
    cmpl %edx, 8(%ebp)                  // Compare n:j
    jg .L30


// Arow     esi
// Bptr     ecx
// j        edx
// result   ebx
// n      edi
.L30:
    movl (%ecx), %eax                   // get *Bptr
    imull (%esi, %edx, 4), %eax         // Arow[j]
    addl %eax, %ebx                     // add to result
    addl $1, %edx                       // increase j
    sall $2, %edi                       // n*4 => edi
    addl %edi, %ecx                     // Add 4*n to Bptr
    sarl $2, %edi                       // n/4 => edi
    cmpl %edx, %edi                  // Compare n:j
    jg .L30
