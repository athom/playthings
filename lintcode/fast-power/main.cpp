//#include<>
#include<iostream>
#include<sstream>
#include <math.h>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    int mod(unsigned long long x, int m) {
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
        long long m = (long long)(r)* (long long)(r);
        if (n % 2 == 1) {
            m = mod(m, b);
            m = m*a;
            return mod(m, b);
        } else {
            return mod(m, b);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.fastPower(109, 10000007, 1000001) == 5249911);
    assert(s.fastPower(3, 7, 2) == 2);
    assert(s.fastPower(3, 4, 7) == 3);
    assert(s.fastPower(2, 3, 31) == 2);
    assert(s.fastPower(100, 1000, 1000) == 0);
    assert(s.fastPower(1, 2147483647, 2147483647) == 1);
    assert(s.fastPower(2, 1, 2147483647) == 0);
    assert(s.fastPower(2, 3, 3) == 2);
    assert(s.fastPower(2, 5, 5) == 2);
    assert(s.fastPower(2, 6, 6) == 4);
    assert(s.fastPower(2, 7, 7) == 2);
    assert(s.fastPower(2, 2147483647, 2147483647) == 2);
    return 0;
}
