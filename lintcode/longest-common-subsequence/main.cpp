//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <assert.h>
#include <utility>

using namespace std;

string matrix_to_str(vector<vector<int> > m) {
    ostringstream os;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                os << m[i][j] << endl;
                continue;
            }
            os << m[i][j] << ", ";
        }
        os << endl;
    }
    return os.str();
}

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        int szA = A.size();
        int szB = B.size();
        if (szA == 0 || szB == 0) {
            return 0;
        }

        // init
        vector<vector<int> > m;
        for (int i = 0; i <= szA; ++i) {
            vector<int> v;
            for (int i = 0; i <= szB; ++i) {
                v.push_back(0);
            }
            m.push_back(v);
        }

        // convert
        for (int i = 1; i <= szA; ++i) {
            for (int j = 1; j <= szB; ++j) {
                if (A[i-1] == B[j-1]) {
                    m[i][j] = m[i-1][j-1] + 1;
                } else {
                    m[i][j] = max(m[i-1][j], m[i][j-1]);
                }
            }
        }

        // answer
        return m[szA][szB];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string s1, s2;
    int r;

    s1 = "ABCD";
    s2 = "EDCA";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 1);

    s1 = "ABCD";
    s2 = "EACB";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 2);

    s1 = "ABCD";
    s2 = "CBCE";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 2);

    s1 = "ABCDYEERX";
    s2 = "CBCEYEERYEERX";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 7); //BCYEERX

    s1 = "ABCDYEERX";
    s2 = "CBCEYEERYEERZ";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 6); //BCYEER

    s1 = "";
    s2 = "CBCEYEERY";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 0);

    s1 = "";
    s2 = "";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 0);

    s1 = "Z";
    s2 = "ABC";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 0);

    s1 = "ACE";
    s2 = "FACE";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 3);

    s1 = "A";
    s2 = "ABC";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 1);

    s1 = "FAC";
    s2 = "FACE";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 3); //FAC

    s1 = "FACFNOBODYF";
    s2 = "FACENOBODYZ";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 9); //FACNOBODY

    s1 = "FACF";
    s2 = "FACE";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 3);

    s1 = "FBABCE";
    s2 = "FACE";
    r = s.longestCommonSubsequence(s1, s2);
    assert(r == 4);
    return 0;
}
