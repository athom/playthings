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
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }
        int sz = nums.size();
        if (sz == 1) {
            return 1;
        }

        vector<int> v;
        for (int i = 0; i < sz; ++i) {
            v.push_back(0);
        }


        int r = (1 << 31);
        v[0] = 1;
        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] <= nums[i]) {
                    v[i] = max(v[i], v[j]);
                }
            }
            v[i] += 1;
            r = max(r, v[i]);
        }

        return r;
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
    r = s.longestIncreasingSubsequence(v);
    assert(r == 3);

    int a2[] = {4, 2, 4, 5, 3, 7};
    v = seed_array(a2, 6);
    assert(to_str(v) == "4 2 4 5 3 7 \n");
    r = s.longestIncreasingSubsequence(v);
    assert(r == 4);

    int a3[] = {1, 2, 3, 4, 5, 6};
    v = seed_array(a3, 6);
    assert(to_str(v) == "1 2 3 4 5 6 \n");
    r = s.longestIncreasingSubsequence(v);
    assert(r == 6);

    int a4[] = {6, 5, 4, 3, 2, 1};
    v = seed_array(a4, 6);
    assert(to_str(v) == "6 5 4 3 2 1 \n");
    r = s.longestIncreasingSubsequence(v);
    assert(r == 1);

    int a5[] = {0};
    v = seed_array(a5, 1);
    assert(to_str(v) == "0 \n");
    r = s.longestIncreasingSubsequence(v);
    assert(r == 1);

    int a6[] = {2, 3, 2, 4, 7, 9, 1};
    v = seed_array(a6, 7);
    assert(to_str(v) == "2 3 2 4 7 9 1 \n");
    r = s.longestIncreasingSubsequence(v);
    assert(r == 5);

    v.clear();
    r = s.longestIncreasingSubsequence(v);
    assert(r == 0);
    return 0;
}
