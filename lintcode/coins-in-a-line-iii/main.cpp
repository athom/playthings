//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <assert.h>
#include <utility>

using namespace std;

string matrix_to_str(vector<vector<int> > m) {
    ostringstream os;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                os << m[i][j] << endl;
                continue;
            }
            os << m[i][j] << ", ";
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
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int sz = values.size();
        if (sz < 2) {
            return true;
        }
        if (sz == 2) {
            return values[0] != values[1];
        }

        // Initialize
        vector<vector<int> > x;
        vector<vector<int> > y;
        for (int i = 0; i < sz; ++i) {
            vector<int> vx;
            vector<int> vy;
            for (int i = 0; i < sz; ++i) {
                vx.push_back(0);
                vy.push_back(0);
            }
            x.push_back(vx);
            y.push_back(vy);
        }
        for (int i = 0; i < sz; ++i) {
            x[0][i] = values[i];
            y[0][i] = 0;
        }


        for (int i = 1; i < sz; ++i) {
            for (int j = i; j < sz; ++j) {
                int left = values[j-i] + y[i-1][j];
                int right = values[j] + y[i-1][j-1];
                if (left > right) {
                    x[i][j] = left;
                    y[i][j] = x[i-1][j];
                } else {
                    x[i][j] = right;
                    y[i][j] = x[i-1][j-1];
                }
            }
        }


        return x[sz-1][sz-1] > y[sz-1][sz-1];
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

    int a7[] = {3, 2, 2};
    v = seed_array(a7, 3);
    assert(s.firstWillWin(v) == true);

    int a9[] = {1, 20, 4};
    v = seed_array(a9, 3);
    assert(s.firstWillWin(v) == false);

    int a10[] = {4, 3, 2, 5, 1};
    v = seed_array(a10, 5);
    assert(s.firstWillWin(v) == false);

    int a4[] = {2,2,2,2,2,2};
    v = seed_array(a4, 6);
    assert(s.firstWillWin(v) == false);

    int a0[] = {1, 2, 2};
    v = seed_array(a0, 3);
    assert(s.firstWillWin(v) == true);

    int a1[] = {1, 2, 4};
    v = seed_array(a1, 3);
    assert(s.firstWillWin(v) == true);

    int a2[] = {6,3,4,5,7};
    v = seed_array(a2, 5);
    assert(s.firstWillWin(v) == true);

    int a3[] = {1,3,6,5,3};
    v = seed_array(a3, 5);
    assert(s.firstWillWin(v) == true);

    int a5[] = {1,2,4, 3,4,8, 5,6,12};
    v = seed_array(a5, 9);
    assert(s.firstWillWin(v) == true);

    return 0;
}
