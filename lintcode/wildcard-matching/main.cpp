//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <assert.h>
#include <utility>

using namespace std;

string matrix_to_str(vector<vector<bool> > m) {
    ostringstream os;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                os << m[i][j] << endl;
                continue;
            }
            os << m[i][j] << ", ";
        }
        os << endl;
    }
    return os.str();
}

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        int x = strlen(s);
        int y = strlen(p);

        vector<vector<bool> > M;
        for (int i = 0; i <= x; ++i) {
            vector<bool> v;
            for (int j = 0; j <= y; ++j) {
                v.push_back(false);
            }
            M.push_back(v);
        }

        M[0][0] = true;
        for (int i = 0; s[i] == '*' && i <= x; ++i) {
            M[i+1][0] = true;
        }
        for (int i = 0; s[i] == '*' && i <= y; ++i) {
            M[0][i+1] = true;
        }

        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                if (s[i-1] == '*' || p[j-1] == '*') {
                    M[i][j] = M[i-1][j-1] || M[i][j-1] || M[i-1][j];
                    continue;
                }

                if (s[i-1] == '?' || p[j-1] == '?' || s[i-1] == p[j-1]) {
                    M[i][j] = M[i-1][j-1];
                    continue;
                }

                M[i][j] = false;
            }
        }

        return M[x][y];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    bool r;

    r = s.isMatch("bbabacccbcbbcaaab", "*a*b??b*b");
    assert(r == true);

    r = s.isMatch("aab", "c*a*b");
    assert(r == false);

    r = s.isMatch("?*", "aab");
    assert(r == true);

    r = s.isMatch("?*", "abb");
    assert(r == true);

    r = s.isMatch("", "");
    assert(r == true);

    r = s.isMatch("*", "");
    assert(r == true);

    r = s.isMatch("?", "");
    assert(r == false);

    r = s.isMatch("aa", "aa");
    assert(r == true);

    r = s.isMatch("aa", "");
    assert(r == false);

    r = s.isMatch("a", "a");
    assert(r == true);

    r = s.isMatch("a", "aa");
    assert(r == false);

    r = s.isMatch("a?", "aa");
    assert(r == true);

    r = s.isMatch("a*", "aa");
    assert(r == true);

    r = s.isMatch("*", "aa");
    assert(r == true);

    r = s.isMatch("a*", "aa");
    assert(r == true);

    r = s.isMatch("*a", "aa");
    assert(r == true);

    r = s.isMatch("*a", "aaa");
    assert(r == true);

    r = s.isMatch("*?", "aaa");
    assert(r == true);

    r = s.isMatch("?*", "aa");
    assert(r == true);

    r = s.isMatch("?*", "ab");
    assert(r == true);

    r = s.isMatch("?*", "abb");
    assert(r == true);


    r = s.isMatch("ab", "aa");
    assert(r == false);


    return 0;
}
