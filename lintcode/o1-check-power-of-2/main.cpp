//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        if (n <= 0) {
            return false;
        }
        n = (n&(0x55555555)) + ((n>>1)&(0x55555555));
        n = (n&(0x33333333)) + ((n>>2)&(0x33333333));
        n = (n&(0x0F0F0F0F)) + ((n>>4)&(0x0F0F0F0F));
        n = (n&(0x00FF00FF)) + ((n>>8)&(0x00FF00FF));
        n = (n&(0x0000FFFF)) + ((n>>16)&(0x0000FFFF));

        return n == 1;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    //assert(s.checkPowerOf2(0) == false);
    //assert(s.checkPowerOf2(1) == true);
    assert(s.checkPowerOf2(2) == true);
    assert(s.checkPowerOf2(3) == false);
    assert(s.checkPowerOf2(4) == true);
    assert(s.checkPowerOf2(5) == false);
    assert(s.checkPowerOf2(7) == false);
    assert(s.checkPowerOf2(8) == true);
    assert(s.checkPowerOf2(16) == true);
    assert(s.checkPowerOf2(1024) == true);
    assert(s.checkPowerOf2(1023) == false);
    return 0;
}
