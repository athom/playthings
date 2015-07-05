//#include<>
#include<iostream>
#include<sstream>
#include<stack>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    bool isAlpha(char c) {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9' );
    }
    bool isAlphaEqual(char a, char b) {
        int offset = 'a' - 'A';
        if (a >= 'a') {
            a = a-offset;
        }
        if (b >= 'a') {
            b = b-offset;
        }
        return a== b;
    }
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        int sz = s.size();
        if (sz == 0) {
            return true;
        }

        int left = 0;
        int right = sz-1;
        while (left < right) {
            while(!isAlpha(s[left])){
                left++;
            }
            while(!isAlpha(s[right])) {
                right--;
            }
            if (left >= right) {
                return true;
            }

            if (!isAlphaEqual(s[left], s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string ss;
    ss = "()";
    assert(s.isPalindrome(ss) == true);

    ss = "A man, a plan, a canal: Panama";
    assert(s.isPalindrome(ss) == true);

    ss = "race a car";
    assert(s.isPalindrome(ss) == false);

    ss = "ab";
    assert(s.isPalindrome(ss) == false);

    ss = "a.";
    assert(s.isPalindrome(ss) == true);
    return 0;
}
