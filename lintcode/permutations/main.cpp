//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <algorithm>
#include <assert.h>
#include <utility>

using namespace std;

string to_str(vector<vector<int> > m) {
    ostringstream os;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                os << m[i][j] << " " << endl;
                continue;
            }
            os << m[i][j] << " ";
        }
    }
    return os.str();
}

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
    bool contains(vector<int> v, int e) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == e ) {
                return true;
            }
        }
        return false;
    }
public:
    void helper(vector<vector<int> >& r, vector<int> v, vector<int> nums) {
        if (v.size() == nums.size()) {
            vector<int> rov = v;
            r.push_back(rov);
            return;
        }


        for (int i = 0; i < nums.size(); ++i) {
            if (contains(v, nums[i])) {
                continue;
            }
            v.push_back(nums[i]);
            helper(r, v, nums);
            v.erase(v.begin() + v.size() - 1);
        }

        return;
    }
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int> > r;
        if (nums.empty()) {
            return r;
        }

        vector<int> v;
        helper(r, v, nums);
        return r;
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
    vector<vector<int> > r;

    int a1[] = {1, 2, 3};
    v = seed_array(a1, 3);
    assert(to_str(v) == "1 2 3 \n");
    r = s.permute(v);
    assert(to_str(r) == "1 2 3 \n1 3 2 \n2 1 3 \n2 3 1 \n3 1 2 \n3 2 1 \n");

    return 0;
}
