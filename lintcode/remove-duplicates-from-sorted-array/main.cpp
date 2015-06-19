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
        map<int, bool> m;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (m.find(*it) != m.end()) {
                nums.erase(it);
                it--;
                continue;
            }
            m[*it] = true;
        }
        return m.size();
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
    assert(r == 3);

    int bb2[] = {1, 1, 1, 1, 1};
    v = seed_array(bb2, 5);
    assert(to_str(v) == "1 1 1 1 1 \n");
    r = s.removeDuplicates(v);
    assert(r == 1);

    int bb3[] = {1};
    v = seed_array(bb3, 1);
    assert(to_str(v) == "1 \n");
    r = s.removeDuplicates(v);
    assert(r == 1);

    v.clear();
    r = s.removeDuplicates(v);
    assert(r == 0);

    int bb4[] = {-14,-14,-13,-13,-13,-13,-13,-13,-13,-12,-12,-12,-12,-11,-10,-9,-9,-9,-8,-7,-5,-5,-5,-5,-4,-3,-3,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,1,1,1,1,2,2,2,3,3,3,4,4,4,4,5,5,5,6,6,6,6,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,14,14,14,14,15,16,16,16,18,18,18,19,19,19,19,20,20,20,21,21,21,21,21,21,22,22,22,22,22,23,23,24,25,25};
    v = seed_array(bb4, 109);
    r = s.removeDuplicates(v);
    assert(r == 38);
    return 0;
}
