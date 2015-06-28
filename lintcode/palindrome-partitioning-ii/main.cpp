//#include<>
#include<string>
#include<iostream>
#include<vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    vector<vector<bool> > palindromeRange(string s) {
        vector<vector<bool> > m;
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            vector<bool> v;
            for (int i = 0; i < sz; ++i) {
                v.push_back(false);
            }
            m.push_back(v);
        }
        for (int i = 0; i < sz; ++i) {
            m[i][i] = true;
        }

        for (int c = 1; c < sz; ++c) {
            for (int i = 0; i < sz; ++i) {
                if (i+c >=sz) {
                    continue;
                }

                if (s[i] != s[i+c]) {
                    continue;
                }

                if (c == 1) {
                    m[i][i+c] = true;
                } else {
                    m[i][i+c] = m[i+1][i+c-1];
                }
            }
        }

        return m;
    }
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
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        int sz = s.size();
        if (sz == 0 || sz == 1) {
            return 0;
        }

        vector<int> v;
        for (int i = 0; i < sz + 1; ++i) {
            v.push_back(0);
        }
        v[0] = -1;

        vector<vector<bool> > m = palindromeRange(s);
        for (int i = 1; i < sz + 1; ++i) {
            int sep =  ~(1<<31);
            for (int j = 0; j < i; ++j) {
                if (m[j][i-1]) {
                    if (v[j] + 1 < sep) {
                        sep = v[j] + 1;
                    }
                }
            }
            v[i] = sep;
        }

        return v[sz];
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    int r;
    vector<vector<bool> > m;

    m = s.palindromeRange("abcbabcb");
    assert(m[0][0] == true);
    assert(m[0][1] == false);
    assert(m[0][2] == false);
    assert(m[0][3] == false);
    assert(m[0][4] == true);
    assert(m[0][5] == false);
    assert(m[0][6] == false);
    assert(m[0][7] == false);

    assert(m[1][1] == true);
    assert(m[1][2] == false);
    assert(m[1][3] == true);
    assert(m[1][4] == false);
    assert(m[1][5] == false);
    assert(m[1][6] == false);
    assert(m[1][7] == true);

    assert(m[2][2] == true);
    assert(m[2][3] == false);
    assert(m[2][4] == false);
    assert(m[2][5] == false);
    assert(m[2][6] == true);
    assert(m[2][7] == false);

    assert(m[3][3] == true);
    assert(m[3][4] == false);
    assert(m[3][5] == true);
    assert(m[3][6] == false);
    assert(m[3][7] == false);

    assert(m[4][4] == true);
    assert(m[4][5] == false);
    assert(m[4][6] == false);
    assert(m[4][7] == false);

    assert(m[5][5] == true);
    assert(m[5][6] == false);
    assert(m[5][7] == true);

    assert(m[6][6] == true);
    assert(m[6][7] == false);

    assert(m[7][7] == true);

    r = s.minCut("aab");
    assert(r == 1);

    r = s.minCut("abcd");
    assert(r == 3);

    r = s.minCut("a");
    assert(r == 0);

    r = s.minCut("abcbabcb");
    assert(r == 1);

    r = s.minCut("");
    assert(r == 0);

    r = s.minCut("abbab");
    assert(r == 1);

    return 0;
}
