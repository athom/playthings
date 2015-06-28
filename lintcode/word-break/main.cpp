//#include<>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_set>
#include <assert.h>

using namespace std;

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (dict.empty() && s.empty()) {
            return true;
        }
        if (dict.empty()) {
            return false;
        }
        if (s.empty()) {
            return false;
        }

        int maxLen = (1<<31);
        int minLen = ~maxLen;
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
            int sz = (*it).size();
            if (sz > maxLen) {
                maxLen = sz;
            }
            if (sz < minLen) {
                minLen = sz;
            }
        }

        vector<bool> v;
        v.push_back(true);
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            v.push_back(false);
        }

        for (int i = 1; i <= sz; ++i) {
            for (int j = i-1; j >= 0 && j >= i-maxLen; --j) {
                if (!v[j]) {
                    continue;
                }
                string word = s.substr(j, i-j);
                if (dict.find(word) != dict.end()) {
                    v[i] = true;
                }
            }
        }


        return v[sz];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string s1;
    unordered_set<string> d;
    bool r;

    d.clear();
    d.insert("leet");
    d.insert("code");
    r = s.wordBreak("leetcode", d);
    assert(r == true);

    d.clear();
    d.insert("leet");
    d.insert("code");
    r = s.wordBreak("leetcodetoo", d);
    assert(r == false);

    d.clear();
    d.insert("no");
    d.insert("fuck");
    r = s.wordBreak("leetcodetoo", d);
    assert(r == false);

    d.clear();
    r = s.wordBreak("leetcodetoo", d);
    assert(r == false);

    d.clear();
    d.insert("a");
    r = s.wordBreak("leetcodetoo", d);
    assert(r == false);

    d.clear();
    d.insert("a");
    r = s.wordBreak("haha", d);
    assert(r == false);

    d.clear();
    d.insert("ha");
    r = s.wordBreak("haha", d);
    assert(r == true);

    d.clear();
    r = s.wordBreak("", d);
    assert(r == true);
    return 0;
}
