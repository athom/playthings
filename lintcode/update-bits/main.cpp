//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int iMask;
        int jMask;
        iMask = ~((~0) << i);   // 00000000011
        if (j == 31) {
           jMask = 0;
        } else {
            jMask = ((~0) << (j+1));    // 11110000000
        }
        int mask = iMask | jMask;
        return (n & mask) | (m << i);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    //assert(s.updateBits(1024, 21, 2, 6) == 1108);
    //cout << s.updateBits(-512, 0, 31, 31) << endl;
    int a = s.updateBits(-512, 0, 31, 31);
    printf("%x\n", a);
    printf("%d\n", a);
    //assert(s.updateBits(-512, 0, 31, 31) == 2147483127);
    int b = -512;
    printf("%x\n", b);

    int c = 0x7ffffe00;
    printf("%d\n", c);
    return 0;
}
