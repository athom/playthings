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
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > r;
        vector<int> v;

        sort(nums.begin(), nums.end());
        helper(r, v, nums, 0);
        return r;
    }

    void helper(vector<vector<int> > & r, vector<int> & v, vector<int> nums, int pos) {
        r.push_back(v);

        for (int i = pos; i < nums.size(); ++i) {
            v.push_back(nums[i]);
            helper(r, v, nums, i+1);
            v.erase(v.begin() + v.size() - 1);
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
    vector<vector<int> > r;

    int a1[] = {1, 2, 3};
    v = seed_array(a1, 3);
    assert(to_str(v) == "1 2 3 \n");
    r = s.subsets(v);
    cout << to_str(r) << endl;
    //assert(to_str(r) == "3 \n1 \n2 \n1 2 3 \n1 3 \n1 2 \n \n");

    return 0;
}
