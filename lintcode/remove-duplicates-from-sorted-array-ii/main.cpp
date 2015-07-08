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
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        map<int, int> m;
        int sz = nums.size();
        if (sz <= 2) {
            return sz;
        }

        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
                count++;
            } else {
                if (m.at(nums[i]) == 2) {
                    nums.erase(nums.begin() + i);
                    i--;
                    continue;
                }
                m[nums[i]]++;
                count++;
            }
        }

        return count;
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

    int bb1[] = {1, 1, 2, 3, 3};
    v = seed_array(bb1, 5);
    assert(to_str(v) == "1 1 2 3 3 \n");
    r = s.removeDuplicates(v);
    assert(r == 5);

    int bb2[] = {1, 1, 1, 1, 1};
    v = seed_array(bb2, 5);
    assert(to_str(v) == "1 1 1 1 1 \n");
    r = s.removeDuplicates(v);
    assert(r == 2);

    int bb3[] = {1};
    v = seed_array(bb3, 1);
    assert(to_str(v) == "1 \n");
    r = s.removeDuplicates(v);
    assert(r == 1);

    int bb4[] = {1, 1, 1, 2, 2, 3};
    v = seed_array(bb4, 6);
    assert(to_str(v) == "1 1 1 2 2 3 \n");
    r = s.removeDuplicates(v);
    assert(r == 5);

    int bb5[] = {-14,-14,-14,-14,-14,-14,-14,-13,-13,-13,-13,-12,-11,-11,-11,-9,-9,-9,-7,-7,-7,-6,-6,-5,-5,-5,-4,-4,-4,-3,-3,-3,-2,-2,-2,-1,-1,0,0,0,0,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,5,5,6,6,6,7,7,7,7,8,8,8,8,9,9,10,10,11,11,11,11,11,12,12,12,12,13,13,13,13,14,14,15,16,17,18,18,18,20,20,21,21,21,21,21,22,22,22,22,23,24,24,25};
    v = seed_array(bb5, 109);
    r = s.removeDuplicates(v);
    assert(r == 68);

    v.clear();
    r = s.removeDuplicates(v);
    assert(r == 0);

    return 0;
}
