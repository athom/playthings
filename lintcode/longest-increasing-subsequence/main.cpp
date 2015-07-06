//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int sz = A.size();
        if (sz < 3) {
            return sz;
        }

        int lastOrder = 0;
        int order = 0;
        int longest = 0;
        int meanOrderLongest = 0;
        int max = 1<<31;

        for (int i = 0; i < sz; ++i) {
            if (i == 0) {
                order = 0;
                lastOrder = 0;
                longest = 1;
                meanOrderLongest = 1;
                if (longest > max) {
                    max = longest;
                }
                continue;
            }

            lastOrder = order;
            if (A[i] > A[i-1]) {
                order = 1;
            } else if (A[i] < A[i-1]) {
                order = -1;
            }


            if (lastOrder * order == -1) {
                longest = 2;
                meanOrderLongest = 1;
            } else if (order == 0 && lastOrder != 0) {
                longest++;
                meanOrderLongest++;
            } else if (order != 0 && lastOrder == 0) {
                longest = meanOrderLongest+1;
                meanOrderLongest = 1;
            } else {
                longest++;
                meanOrderLongest = 1;
            }

            if (longest > max) {
                max = longest;
            }
        }

        return max;
    }
};

string to_str(vector<int> s){
    ostringstream os;
    int i = 0;
    while(i<s.size()){
        os << s[i] << " ";
        i++;
    }
    os << endl;
    return os.str();
}

vector<int> seed_array(const int* a, int len) {
    vector<int> v;
    for (int i = 0; i < len; i++) {
        v.push_back(a[i]);
    }

    return v;
}

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v;
    int r;

    int a1[] = {5, 4, 1, 2, 3};
    v = seed_array(a1, 5);
    assert(to_str(v) == "5 4 1 2 3 \n");
    r = s.longestIncreasingContinuousSubsequence(v);
    assert(r == 3);

    int a2[] = {4, 2, 4, 5, 3, 7};
    v = seed_array(a2, 6);
    assert(to_str(v) == "4 2 4 5 3 7 \n");
    r = s.longestIncreasingContinuousSubsequence(v);
    assert(r == 3);

    int a3[] = {1, 2, 3, 4, 5, 6};
    v = seed_array(a3, 6);
    assert(to_str(v) == "1 2 3 4 5 6 \n");
    r = s.longestIncreasingContinuousSubsequence(v);
    assert(r == 6);

    int a4[] = {6, 5, 4, 3, 2, 1};
    v = seed_array(a4, 6);
    assert(to_str(v) == "6 5 4 3 2 1 \n");
    r = s.longestIncreasingContinuousSubsequence(v);
    assert(r == 6);

    int a5[] = {0};
    v = seed_array(a5, 1);
    assert(to_str(v) == "0 \n");
    r = s.longestIncreasingContinuousSubsequence(v);
    assert(r == 1);

    int a6[] = {2, 3, 2, 4, 7, 9, 1};
    v = seed_array(a6, 7);
    assert(to_str(v) == "2 3 2 4 7 9 1 \n");
    r = s.longestIncreasingContinuousSubsequence(v);
    assert(r == 4);

    int a7[] = {2, 3, 2, 2, 4, 7, 9, 1};
    v = seed_array(a7, 8);
    assert(to_str(v) == "2 3 2 2 4 7 9 1 \n");
    r = s.longestIncreasingContinuousSubsequence(v);
    assert(r == 5);

    v.clear();
    r = s.longestIncreasingContinuousSubsequence(v);
    assert(r == 0);
    return 0;
}
