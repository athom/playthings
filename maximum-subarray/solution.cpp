#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int thisSum = 0;
        int maxSum = -99999;

        for (int i = 0; i < n; ++i)
        {
            thisSum += A[i];

            if (thisSum > maxSum)
            {
                maxSum = thisSum;
            }

            if (thisSum < 0)
            {
                thisSum = 0;
            }

        }
        return maxSum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int a[10] = {-2,1,-3,4,-1,2,1,-5,4};
    assert(s.maxSubArray(a, 9) == 6);

    int b[10] = {-1};
    assert(s.maxSubArray(b, 1) == -1);

    int c[10] = {-3, -2, 0, -1};
    assert(s.maxSubArray(c, 4) == 0);

    int d[10] = {-2, -1};
    assert(s.maxSubArray(d, 2) == -1);
    return 0;
}
