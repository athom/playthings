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
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        int sz1 = s1.size();
        int sz2 = s2.size();
        int sz3 = s3.size();

        if (sz1 + sz2 != sz3) {
            return false;
        }

        vector<vector<bool> > m;
        for (int i = 0; i <= sz1; ++i) {
            vector<bool> v;
            for (int j = 0; j <= sz2; ++j) {
                v.push_back(false);
            }
            m.push_back(v);
        }
        m[0][0] = true;

        for (int i = 1; i <= sz2; ++i) {
            m[0][i] = m[0][i-1] && s2[i-1] == s3[i-1];
        }
        for (int i = 1; i <= sz1; ++i) {
            m[i][0] = m[i-1][0] && s1[i-1] == s3[i-1];
        }

        for (int i = 1; i <= sz1; ++i) {
            for (int j = 1; j <= sz2; ++j) {
                if (m[i-1][j-1] && ((s1[i-1] == s3[i+j-2] && s2[j-1] == s3[i+j-1]) || (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-2]))) {
                    m[i][j] = true;
                    continue;
                }
                if (m[i-1][j] && ((s1[i-1] == s3[i+j-2]) || (s1[i-1] == s3[i+j-1]))) {
                    m[i][j] = true;
                    continue;
                }
                if (m[i][j-1] && ((s2[j-1] == s3[i+j-2]) || (s2[j-1] == s3[i+j-1]))) {
                    m[i][j] = true;
                    continue;
                }
            }
        }

        return m[sz1][sz2];
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    string s1, s2, s3;
    bool r;

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";
    r = s.isInterleave(s1, s2, s3);
    assert(r == true);

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbbaccc";
    r = s.isInterleave(s1, s2, s3);
    assert(r == false);

    s1 = "";
    s2 = "";
    s3 = "";
    r = s.isInterleave(s1, s2, s3);
    assert(r == true);

    s1 = "a";
    s2 = "b";
    s3 = "ab";
    r = s.isInterleave(s1, s2, s3);
    assert(r == true);

    s1 = "a";
    s2 = "b";
    s3 = "ba";
    r = s.isInterleave(s1, s2, s3);
    assert(r == true);

    s1 = "a";
    s2 = "b";
    s3 = "b";
    r = s.isInterleave(s1, s2, s3);
    assert(r == false);

    s1 = "a";
    s2 = "";
    s3 = "a";
    r = s.isInterleave(s1, s2, s3);
    assert(r == true);
    return 0;
}
