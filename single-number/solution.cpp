#include <iostream>
using namespace std;


class Solution {
public:
    int singleNumber(int A[], int n) {
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            num ^= A[i];
        }    
        return num;
    }
};

int main(int argc, char *argv[])
{
    cout << "hi" << endl;
    int A[] = {1,2,1,2,5,6,7,7,6};
    Solution s;
    cout << s.singleNumber(A, 9) << endl;
    return 0;
}
