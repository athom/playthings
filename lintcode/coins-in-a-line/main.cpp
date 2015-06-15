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
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
         return n % 3 != 0;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    assert(s.firstWillWin(1) == true);
    assert(s.firstWillWin(2) == true);
    assert(s.firstWillWin(3) == false);
    assert(s.firstWillWin(4) == true);
    assert(s.firstWillWin(5) == true);
    assert(s.firstWillWin(6) == false);
    return 0;
}
