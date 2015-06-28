//#include<>
#include<string>
#include<iostream>
#include<vector>
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

        for (int i = 1; i < sz + 1; ++i) {
            int sep =  ~(1<<31);
            for (int j = 0; j < i; ++j) {
                string word = s.substr(j, i-j);
                if (isPalindrome(word)) {
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
