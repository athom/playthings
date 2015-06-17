//#include<>
#include<string>
#include<iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        const char* pSrc = source;
        const char* pTgt = target;
        const char* ps;
        const char* pt;
        if (pSrc == NULL || pTgt == NULL) {
            return -1;
        }
        if (*pTgt == '\0') {
            return 0;
        }
        if (*pSrc == '\0') {
            return -1;
        }

        int i = 0;
        int lastIndex = 0;
        const char* lastPos = NULL;
        while (pSrc) {
            ps = pSrc;
            pt = pTgt;
            i = lastIndex;

            while (ps && pt && *ps!= '\0' && *pt != '\0' && *ps != *pt) {
                i++;
                ps++;
            }
            if (ps == NULL || *ps == '\0') {
                return -1;
            }

            while (ps && pt && *ps != '\0' && *pt != '\0' && *ps == *pt) {
                ps++;
                pt++;
            }

            if (pt == NULL || *pt == '\0') {
                return i;
            }
            if (ps == NULL || *ps == '\0') {
                return -1;
            }

            lastIndex++;
            pSrc++;
        }

        return -1;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    int r;

    r = s.strStr("abc", NULL);
    assert(r == -1);

    r = s.strStr(NULL, NULL);
    assert(r == -1);

    r = s.strStr(NULL, "ac");
    assert(r == -1);

    r = s.strStr("abc", "bc");
    assert(r == 1);

    r = s.strStr("abc", "b");
    assert(r == 1);

    r = s.strStr("abc", "a");
    assert(r == 0);

    r = s.strStr("abc", "c");
    assert(r == 2);

    r = s.strStr("source", "target");
    assert(r == -1);

    r = s.strStr("abcdabcdefg", "bcd");
    assert(r == 1);

    r = s.strStr("abcdabcdefg", "bcde");
    assert(r == 5);

    r = s.strStr("", "");
    assert(r == 0);

    r = s.strStr("", "ac");
    assert(r == -1);

    r = s.strStr("ababc", "a");
    assert(r == 0);

    r = s.strStr("ababc", "");
    assert(r == 0);
    return 0;
}
