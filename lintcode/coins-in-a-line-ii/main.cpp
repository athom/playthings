//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int sz = values.size();
        if (sz <= 2) {
            return true;
        }

        int sum = 0;
        for (int i = 0; i < sz; ++i) {
            sum += values[i];
        }

        vector<int> f;
        f.push_back(0);
        f.push_back(values[sz-1]);
        f.push_back(values[sz-2] + values[sz-1]);
        f.push_back(values[sz-3] + values[sz-2]);

        for (int i = 4; i <= sz; ++i) {
            int take_two = values[sz-i] + values[sz-i+1] + f[i-4];
            int take_one = values[sz-i] + f[i-3];
            f.push_back(max(take_one, take_two));
        }

        return f[sz] > (sum - f[sz]);
    }
};

vector<int> seed_array(const int* a, int len) {
    vector<int> v;
    for (int i = 0; i < len; i++) {
        v.push_back(a[i]);
    }
    return v;
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


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v;

    int a4[] = {2,2,2,2,2,2};
    v = seed_array(a4, 6);
    assert(s.firstWillWin(v) == true);

    int a0[] = {1, 2, 2};
    v = seed_array(a0, 3);
    assert(s.firstWillWin(v) == true);

    int a1[] = {1, 2, 4};
    v = seed_array(a1, 3);
    assert(s.firstWillWin(v) == false);

    int a2[] = {6,3,4,5,7};
    v = seed_array(a2, 5);
    assert(s.firstWillWin(v) == true);

    int a3[] = {1,3,6,5,3};
    v = seed_array(a3, 5);
    assert(s.firstWillWin(v) == false);

    int a5[] = {100,200,400, 300,400,800, 500,600,1200};
    v = seed_array(a5, 9);
    assert(s.firstWillWin(v) == true);

    return 0;
}
