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
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int c = a ^ b;
        int sum = 0;
        int mask = 0x01010101;
        sum += (c >> 0) & mask;
        sum += (c >> 1) & mask;
        sum += (c >> 2) & mask;
        sum += (c >> 3) & mask;
        sum += (c >> 4) & mask;
        sum += (c >> 5) & mask;
        sum += (c >> 6) & mask;
        sum += (c >> 7) & mask;

        sum += (sum >> 16);
        sum += (sum >> 8);

        return sum & 0xFF;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.bitSwapRequired(31, 14) == 2);
    assert(s.bitSwapRequired(31, 31) == 0);
    assert(s.bitSwapRequired(0, 0) == 0);
    assert(s.bitSwapRequired(0, 1) == 1);
    assert(s.bitSwapRequired(0, 3) == 2);
    assert(s.bitSwapRequired(7, 3) == 1);
    assert(s.bitSwapRequired(14, 23) == 3);

    return 0;
}
