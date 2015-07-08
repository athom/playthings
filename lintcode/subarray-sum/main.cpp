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
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> v;
        int sz = nums.size();
        if (sz == 0) {
            return v;
        }

        int sum = 0;
        map<int, int> m;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] == 0) {
                v.push_back(i);
                v.push_back(i);
                return v;
            }
            sum += nums[i];
            if (sum == 0) {
                v.push_back(0);
                v.push_back(i);
                return v;
            }


            if (m.find(sum) != m.end()) {
                v.push_back(m.at(sum)+1);
                v.push_back(i);
                return v;
            }
            m[sum] = i;
        }


        return v;
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
    vector<int> r;

    int a4[] = {-5,10,5,-3,1,1,1,-2,3,-4};

    v = seed_array(a4, 10);
    assert(to_str(v) == "-5 10 5 -3 1 1 1 -2 3 -4 \n");
    r = s.subarraySum(v);
    assert(r[0] == 3);
    assert(r[1] == 6);

    int a1[] = {1, 2, 3, -1, -1, -1};
    v = seed_array(a1, 6);
    assert(to_str(v) == "1 2 3 -1 -1 -1 \n");
    r = s.subarraySum(v);
    assert(r[0] == 2);
    assert(r[1] == 5);

    int a2[] = {-3, 1, 2, -3, 4};
    v = seed_array(a2, 5);
    assert(to_str(v) == "-3 1 2 -3 4 \n");
    r = s.subarraySum(v);
    assert(r[0] == 0);
    assert(r[1] == 2);

    int a3[] = {5, -3, 1, 2, -3, 4};
    v = seed_array(a3, 6);
    assert(to_str(v) == "5 -3 1 2 -3 4 \n");
    r = s.subarraySum(v);
    assert(r[0] == 1);
    assert(r[1] == 3);


    int a5[] = {1, -1};
    v = seed_array(a5, 2);
    assert(to_str(v) == "1 -1 \n");
    r = s.subarraySum(v);
    assert(r[0] == 0);
    assert(r[1] == 1);

    return 0;
}
