//#include<>
#include<iostream>
#include<sstream>
#include <math.h>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    int mod(int x, int m) {
        if (m == 1) {
            return 0;
        }

        int r = x % m;
        if (r < 0) {
            return m+r;
        }
        return r;
    }
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if (n ==0) {
            return mod(1, b);
        }

        if (n == 1) {
            return mod(a, b);
        }

        int r = fastPower(a, b, n/2);
        if (n % 2 == 0) {
            return mod(r*r, b);
        } else {
            return mod(r*r*a, b);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.fastPower(3, 7, 2) == 2);
    assert(s.fastPower(3, 4, 7) == 3);
    assert(s.fastPower(2, 3, 31) == 2);
    assert(s.fastPower(100, 1000, 1000) == 0);
    assert(s.fastPower(1, 2147483647, 2147483647) == 1);
    return 0;
}
