//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    int fixedLongestCommonSubstring(string &A, string& B) {
        string shortStr;
        string longStr;
        if (A.size() > B.size()) {
            shortStr = B;
            longStr = A;
        } else {
            shortStr = A;
            longStr = B;
        }

        int shortSz = shortStr.size();
        int longSz = longStr.size();
        int sz = 0;
        int curSz = 0;
        int i = 0;
        while (i < shortSz) {
            int j = 0;
            curSz = 0;
            while((i+j<shortSz) && shortStr[i+j] == longStr[i+j]) {
                j++;
                curSz++;
            }
            if (curSz > sz) {
                sz = curSz;
            }
            i++;
        }
        return sz;
    }
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        if (A.size() == 0 || B.size() == 0) {
            return 0;
        }

        string shortStr;
        string longStr;
        if (A.size() > B.size()) {
            shortStr = B;
            longStr = A;
        } else {
            shortStr = A;
            longStr = B;
        }

        int maxSize = 0;
        while (!longStr.empty()) {
            int sz = fixedLongestCommonSubstring(shortStr, longStr);
            //cout << sz << endl;
            if (sz > maxSize) {
                maxSize = sz;
            }
            longStr.erase(0,1);
            //cout << longStr << endl;
        }

        return maxSize;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string s1, s2;
    int r;

    //r = s.longestCommonSubstring("ABCD", "CBCE");
    //assert(r == "BC");
    s1 = "ABCD";
    s2 = "CBCE";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 2);

    s1 = "ABCDYEERX";
    s2 = "CBCEYEERYEERX";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 5);

    s1 = "ABCDYEERX";
    s2 = "CBCEYEERYEERZ";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 4);

    s1 = "";
    s2 = "CBCEYEERY";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 0);

    s1 = "";
    s2 = "";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 0);

    s1 = "Z";
    s2 = "ABC";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 0);

    s1 = "ACE";
    s2 = "FACE";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 3);

    s1 = "A";
    s2 = "ABC";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 1);

    s1 = "FAC";
    s2 = "FACE";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 3);

    s1 = "FACFNOBODYF";
    s2 = "FACENOBODYZ";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 6);

    s1 = "FACF";
    s2 = "FACE";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 3);

    s1 = "FACE";
    s2 = "FACE";
    r = s.longestCommonSubstring(s1, s2);
    assert(r == 4);
    return 0;
}
