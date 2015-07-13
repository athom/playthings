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
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        for (int i = 2; i <= n; ++i) {
            int sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += v[j]*v[i-j-1];
            }
            v.push_back(sum);
        }

        return v[n];
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
    int r;

    r = s.numTrees(1);
    assert(r == 1);

    r = s.numTrees(2);
    assert(r == 2);

    r = s.numTrees(3);
    assert(r == 5);

    r = s.numTrees(4);
    assert(r == 14);

    r = s.numTrees(5);
    assert(r == 42);

    return 0;
}
