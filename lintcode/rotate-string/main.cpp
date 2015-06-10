//#include<>
#include<string>
#include<iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        if (A == "")
        {
            return "";
        }

        string B = A;
        int size = A.size();
        offset %= size;
        if (offset<0)
        {
            offset += size;
        }

        for (int i = 0; i < (size-offset); ++i)
        {
            B[i+offset] = A[i];
        }

        for (int i = 0; i < offset; ++i)
        {
            B[i] = A[size-offset+i];
        }

        return B;
    }
};



int main(int argc, char *argv[])
{
    Solution s;
    string r;

    r = s.rotateString("", 0);
    assert(r == "");

    r = s.rotateString("a", 0);
    assert(r == "a");
    r = s.rotateString("a", 1);
    assert(r == "a");
    r = s.rotateString("a", 100);
    assert(r == "a");

    r = s.rotateString("aaaaaa", 23);
    assert(r == "aaaaaa");

    r = s.rotateString("abcdef", 0);
    assert(r == "abcdef");

    r = s.rotateString("abcdef", 1);
    assert(r == "fabcde");

    r = s.rotateString("abcdef", 2);
    assert(r == "efabcd");

    r = s.rotateString("abcdef", 3);
    assert(r == "defabc");

    r = s.rotateString("abcdef", 4);
    assert(r == "cdefab");

    r = s.rotateString("abcdef", 5);
    assert(r == "bcdefa");

    r = s.rotateString("abcdef", 6);
    assert(r == "abcdef");

    r = s.rotateString("abcdef", 7);
    assert(r == "fabcde");

    r = s.rotateString("abcdef", -1);
    assert(r == "bcdefa");

    r = s.rotateString("abcdef", -2);
    assert(r == "cdefab");
    return 0;
}
