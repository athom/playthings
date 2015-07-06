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
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        if (sz == 1) {
            return nums[0];
        }

        int maxSumContainsMe = 0;
        int max = 1<<31;
        for (int i = 0; i < sz; ++i) {
            if (i == 0) {
                maxSumContainsMe = nums[i];
                max = maxSumContainsMe;
                continue;
            }
            int r = nums[i] + maxSumContainsMe;
            if (r > nums[i]) {
                maxSumContainsMe = r;
            } else {
                maxSumContainsMe = nums[i];
            }

            if (maxSumContainsMe > max) {
                max = maxSumContainsMe;
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

    int a1[] = {1, 2, 3, -1, -1};
    v = seed_array(a1, 5);
    assert(to_str(v) == "1 2 3 -1 -1 \n");
    r = s.maxSubArray(v);
    assert(r == 6);

    int a2[] = {1, 2, 3, 4, 5};
    v = seed_array(a2, 5);
    assert(to_str(v) == "1 2 3 4 5 \n");
    r = s.maxSubArray(v);
    assert(r == 15);

    int a3[] = {1, -1, -2, 1};
    v = seed_array(a3, 4);
    assert(to_str(v) == "1 -1 -2 1 \n");
    r = s.maxSubArray(v);
    assert(r == 1);

    int a4[] = {1, 1};
    v = seed_array(a4, 2);
    assert(to_str(v) == "1 1 \n");
    r = s.maxSubArray(v);
    assert(r == 2);


    int a6[] = {-4,5,-4,5,-4, 5,-4,5,-4,5,  -4,5,-4,5,-4,   5,-4,5,-1000};
    v = seed_array(a6, 19);
    r = s.maxSubArray(v);
    assert(r == 13);

    int a7[] = {-2,2,-3,4,-1,2,1,-5,3};
    v = seed_array(a7, 9);
    r = s.maxSubArray(v);
    assert(r == 6);

    int a8[] = {1};
    v = seed_array(a8, 1);
    assert(to_str(v) == "1 \n");
    r = s.maxSubArray(v);
    assert(r == 1);

    int a9[] = {-14};
    v = seed_array(a9, 1);
    assert(to_str(v) == "-14 \n");
    r = s.maxSubArray(v);
    assert(r == -14);

    v.clear();
    r = s.maxSubArray(v);
    assert(r == 0);
    return 0;
}
