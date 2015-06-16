//#include<>
#include<string>
#include<iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if (B.size() == 0) {
            return true;
        }

        if (A.size() < B.size()) {
            return false;
        }

        if (A.size() == 0) {
            return B.size() == 0;
        }


        bool found = false;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == B[0]) {
                A.erase(i, 1);
                B.erase(0,1);
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }

        return compareStrings(A, B);
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    bool r;

    r = s.compareStrings("", "");
    assert(r == true);

    r = s.compareStrings("ABC", "B");
    assert(r == true);

    r = s.compareStrings("ABC", "ABC");
    assert(r == true);

    r = s.compareStrings("ABC", "CBA");
    assert(r == true);

    r = s.compareStrings("ABCD", "");
    assert(r == true);

    r = s.compareStrings("ABCD", "ACD");
    assert(r == true);

    r = s.compareStrings("", "B");
    assert(r == false);

    r = s.compareStrings("ABCD", "AABC");
    assert(r == false);

    r = s.compareStrings("ABC", "CBAA");
    assert(r == false);

    r = s.compareStrings("ABCD", "AAAAA");
    assert(r == false);
    return 0;
}
