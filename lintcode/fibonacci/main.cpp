//#include<>
#include<iostream>
#include<sstream>
#include <math.h>
#include <assert.h>
#include <utility>

using namespace std;

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        double h1 = (1+sqrt(5))/2.0;
        double h2 = (1-sqrt(5))/2.0;
        return int((pow(h1, n-1) - pow(h2, n-1)) / sqrt(5));
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.fibonacci(1) == 0);
    assert(s.fibonacci(2) == 1);
    assert(s.fibonacci(3) == 1);
    assert(s.fibonacci(4) == 2);
    assert(s.fibonacci(5) == 3);
    assert(s.fibonacci(6) == 5);
    assert(s.fibonacci(7) == 8);
    assert(s.fibonacci(8) == 13);
    assert(s.fibonacci(9) == 21);
    assert(s.fibonacci(10) == 34);
    assert(s.fibonacci(11) == 55);
    return 0;
}
