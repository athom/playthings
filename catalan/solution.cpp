#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += numTrees(i)*numTrees(n-i-1);
        }
        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.numTrees(1) << endl;
    cout << s.numTrees(2) << endl;
    cout << s.numTrees(3) << endl;
    cout << s.numTrees(4) << endl;
    cout << s.numTrees(5) << endl;
    cout << s.numTrees(6) << endl;
    cout << s.numTrees(7) << endl;
    return 0;
}
