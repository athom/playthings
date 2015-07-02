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
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        int INF = ~(1<<31);
        int acc = 0;
        int minSum = INF;
        for (int i = 0; i < sz; ++i) {
            if (acc + nums[i] < minSum) {
                minSum = acc + nums[i];
            }
            if (acc < 0) {
                acc += nums[i];
            } else {
                if (nums[i] < 0) {
                    acc = nums[i];
                }
            }
            if (acc > 0) {
               acc = 0;
            }
        }
        return minSum;
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
    r = s.minSubArray(v);
    assert(r == -2);

    int a2[] = {1, 2, 3, 4, 5};
    v = seed_array(a2, 5);
    assert(to_str(v) == "1 2 3 4 5 \n");
    r = s.minSubArray(v);
    assert(r == 1);

    int a3[] = {1, -1, -2, 1};
    v = seed_array(a3, 4);
    assert(to_str(v) == "1 -1 -2 1 \n");
    r = s.minSubArray(v);
    assert(r == -3);

    int a4[] = {1, 1};
    v = seed_array(a4, 2);
    assert(to_str(v) == "1 1 \n");
    r = s.minSubArray(v);
    assert(r == 1);

    int a5[] = {1,1,1,1,1, 1,1,1,1,-19, 1,1,1,1,1, 1,1,-2,1,1, 1,1,1,1,1, 1,-2,1,-15,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1};
    v = seed_array(a5, 47);
    r = s.minSubArray(v);
    assert(r == -22);

    int a6[] = {-4,5,-4,5,-4, 5,-4,5,-4,5,  -4,5,-4,5,-4,   5,-4,5,-1000};
    v = seed_array(a6, 19);
    r = s.minSubArray(v);
    cout << r << endl;
    assert(r == -1000);

    v.clear();
    r = s.minSubArray(v);
    assert(r == 0);
    return 0;
}
