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
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code
        int i = 0;
        int sum = 0;
        while (i<32) {
            sum += !!(num&(1<<i));
            i++;
        }
        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.countOnes(0) == 0);
    assert(s.countOnes(1) == 1);
    assert(s.countOnes(5) == 2);

    assert(s.countOnes(3) == 2);
    assert(s.countOnes(7) == 3);
    assert(s.countOnes(15) == 4);
    assert(s.countOnes(31) == 5);
    assert(s.countOnes(63) == 6);
    assert(s.countOnes(127) == 7);
    assert(s.countOnes(255) == 8);
    assert(s.countOnes(511) == 9);
    assert(s.countOnes(1023) == 10);

    assert(s.countOnes(32) == 1);
    assert(s.countOnes(64) == 1);
    assert(s.countOnes(128) == 1);
    return 0;
}
