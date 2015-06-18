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
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }

        string prefix = strs[0];
        int i = 1;
        string s;
        while (i < strs.size()) {
            s = strs[i];
            if (s.empty()) {
                return "";
            }

            int j = 0;
            int stop = s.size() < prefix.size() ? s.size() : prefix.size();
            while(j < stop && prefix[j] == s[j]) {
                j++;
            }
            if (j == 0) {
                return "";
            }
            int left_count = prefix.size() - j;
            if (left_count > 0) {
                prefix.erase(j, left_count);
            }
            i++;
        }

        return prefix;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> v;
    string r;

    v.clear();
    v.push_back("dog");
    v.push_back("google");
    v.push_back("facebook");
    v.push_back("internaltional");
    v.push_back("blabla");
    r = s.longestCommonPrefix(v);
    assert(r == "");

    v.clear();
    v.push_back("ABCD");
    v.push_back("ABEF");
    v.push_back("ACEF");
    r = s.longestCommonPrefix(v);
    assert(r == "A");

    v.clear();
    v.push_back("ABCDEFG");
    v.push_back("ABCEFG");
    v.push_back("ABCEFA");
    r = s.longestCommonPrefix(v);
    assert(r == "ABC");

    v.clear();
    r = s.longestCommonPrefix(v);
    assert(r == "");

    v.clear();
    v.push_back("");
    r = s.longestCommonPrefix(v);
    assert(r == "");

    v.clear();
    v.push_back("ababac");
    r = s.longestCommonPrefix(v);
    assert(r == "ababac");
    return 0;
}
