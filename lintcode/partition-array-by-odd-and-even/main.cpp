//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

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

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int sz = nums.size();
        if (sz == 0 || sz == 1) {
            return;
        }

        int changableIndex = 0;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] % 2 != 0) {
                int tmp = nums[changableIndex];
                nums[changableIndex] = nums[i];
                nums[i] = tmp;
                changableIndex++;
            }
        }
    }
};


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

    int a3[] = {1, 2, 2, 3, 4};
    v = seed_array(a3, 5);
    assert(to_str(v) == "1 2 2 3 4 \n");
    s.partitionArray(v);
    assert(to_str(v) == "1 3 2 2 4 \n");

    int a2[] = {1, 2, 3, 4};
    v = seed_array(a2, 4);
    assert(to_str(v) == "1 2 3 4 \n");
    s.partitionArray(v);
    assert(to_str(v) == "1 3 2 4 \n");

    int a1[] = {1, 2, 3, -1, -1};
    v = seed_array(a1, 5);
    assert(to_str(v) == "1 2 3 -1 -1 \n");
    s.partitionArray(v);
    assert(to_str(v) == "1 3 -1 -1 2 \n");

    return 0;
}
