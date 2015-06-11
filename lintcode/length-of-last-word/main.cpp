//#include<>
#include<string>
#include<iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int count = 0;
        int len = s.size();
        int index = len-1;

        // Skip right margin
        while (s[index] == ' ' && index>=0) {
            index--;
        }

        while (s[index] != ' ' && index>=0) {
            index--;
            count++;
        }

        return count;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    int r;
    string ss;

    ss = "";
    r = s.lengthOfLastWord(ss);
    assert(r == 0);

    ss = " ";
    r = s.lengthOfLastWord(ss);
    assert(r == 0);

    ss = "  ";
    r = s.lengthOfLastWord(ss);
    assert(r == 0);

    ss = "a";
    r = s.lengthOfLastWord(ss);
    assert(r == 1);

    ss = "a ";
    r = s.lengthOfLastWord(ss);
    assert(r == 1);

    ss = " a";
    r = s.lengthOfLastWord(ss);
    assert(r == 1);

    ss = " a ";
    r = s.lengthOfLastWord(ss);
    assert(r == 1);

    ss = "hello world";
    r = s.lengthOfLastWord(ss);
    assert(r == 5);

    ss = "hello world ";
    r = s.lengthOfLastWord(ss);
    assert(r == 5);

    ss = "hello world  ";
    r = s.lengthOfLastWord(ss);
    assert(r == 5);
    return 0;
}
