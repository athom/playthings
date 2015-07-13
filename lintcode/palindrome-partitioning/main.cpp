//#include<>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            if (s[i] != s[sz - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string> > partition(string s) {
        vector<vector<string> > m;
        int sz = s.size();
        if (sz == 0) {
            return m;
        }
        if (sz == 1) {
           vector<string> v;
           v.push_back(s);
           m.push_back(v);
           return m;
        }

        vector<string> path;
        helper(m, path, s, 0);

        return m;
    }

    void helper(vector<vector<string> >& r, vector<string> path, string s, int pos) {
        if (pos == s.size()) {
            vector<string> v = path;
            r.push_back(v);
            return;
        }

        for (int i = pos + 1; i <= s.size(); ++i) {
            string prefix = s.substr(pos, i-pos);
            if (!isPalindrome(prefix)) {
                continue;
            }

            path.push_back(prefix);
            helper(r, path, s, i);
            path.erase(path.begin() + path.size()-1);
        }
    }
};

string matrix_to_str(vector<vector<string> > m) {
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

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<string> > r;

    r = s.partition("aab");
    assert(r[0][0] == "a");
    assert(r[0][1] == "a");
    assert(r[0][2] == "b");
    assert(r[1][0] == "aa");
    assert(r[1][1] == "b");

    r = s.partition("abcbab");
    assert(r[0][0] == "a");
    assert(r[0][1] == "b");
    assert(r[0][2] == "c");
    assert(r[0][3] == "b");
    assert(r[0][4] == "a");
    assert(r[0][5] == "b");
    assert(r[1][0] == "a");
    assert(r[1][1] == "b");
    assert(r[1][2] == "c");
    assert(r[1][3] == "bab");
    assert(r[2][0] == "a");
    assert(r[2][1] == "bcb");
    assert(r[2][2] == "a");
    assert(r[2][3] == "b");
    assert(r[3][0] == "abcba");
    assert(r[3][1] == "b");

    r = s.partition("cdd");
    assert(r[0][0] == "c");
    assert(r[0][1] == "d");
    assert(r[0][2] == "d");

    assert(r[1][0] == "c");
    assert(r[1][1] == "dd");

    return 0;
}
