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
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > r;
        vector<int> v;
        helper(r, v, n, k);
        return r;
    }

    bool contains(vector<int> v, int e) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == e ) {
                return true;
            }
        }
        return false;
    }

    void helper(vector<vector<int> >& r, vector<int>& v, int n, int k) {
        if (v.size() == k) {
            vector<int> vv;
            for (int i = 0; i < v.size(); ++i) {
                vv.push_back(v[v.size()-1-i]);
            }
            r.push_back(vv);
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (contains(v, i)) {
                continue;
            }

            v.push_back(i);
            helper(r, v, i, k);
            v.erase(v.begin() + v.size() - 1);
        }

        return;
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

    r = s.combine(4, 4);
    cout << to_str(r) << endl;

    r = s.combine(4, 2);
    cout << to_str(r) << endl;

    r = s.combine(3, 2);
    cout << to_str(r) << endl;
    assert(to_str(r) == "1 2 \n1 3 \n2 3 \n");

    r = s.combine(3, 1);
    cout << to_str(r) << endl;

    r = s.combine(3, 3);
    cout << to_str(r) << endl;

    r = s.combine(5, 3);
    cout << to_str(r) << endl;

    return 0;
}
