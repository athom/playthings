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
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.size() != t.size()) {
            return false;
        }

        if (s.size() == 0) {
            return true;
        }

        if (s.size() == 1) {
            return s[0] == t[0];
        }

        bool found = false;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == s[0]) {
                s.erase(0, 1);
                t.erase(i, 1);
                found = true;
                break;
            }
        }

        if (!found) {
            return false;
        }

        return anagram(s, t);
    }
};


int main(int argc, char *argv[])
{
    Solution s;

    assert(s.anagram("man", "six") == false);
    assert(s.anagram("ab", "ab") == true);
    assert(s.anagram("ab", "ba") == true);
    assert(s.anagram("1234", "4321") == true);
    assert(s.anagram("1234", "3421") == true);
    assert(s.anagram("1234", "43210") == false);
    assert(s.anagram("", "") == true);
    assert(s.anagram("1", "1") == true);
    assert(s.anagram("1", "11") == false);
    assert(s.anagram("12", "12") == true);
    assert(s.anagram("123456", "354126") == true);
    assert(s.anagram("123456", "354127") == false);
    return 0;
}
