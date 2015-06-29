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
    }
    return os.str();
}

class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        int sz1 = S.size();
        int sz2 = T.size();
        if (sz1 < sz2) {
            return 0;
        }
        if (sz1 == sz2) {
            return S == T ? 1 : 0;
        }

        vector<vector<int> > m;
        for (int i = 0; i <= sz1; ++i) {
            vector<int> v;
            for (int j = 0; j <= sz2; ++j) {
                v.push_back(0);
            }
            m.push_back(v);
        }
        for (int i = 0; i <= sz1; ++i) {
            m[i][0] = 1;
        }


        for (int j = 1; j <= sz2; ++j) {
            for (int i = 1; i <= sz1; ++i) {
                if (S[i-1] == T[j-1]) {
                    m[i][j] = m[i-1][j] + m[i-1][j-1];
                } else {
                    m[i][j] = m[i-1][j];
                }
            }
        }

        return m[sz1][sz2];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string s1, s2;
    int r;

    s1 = "rabbbit";
    s2 = "rabbit";
    r = s.numDistinct(s1, s2);
    assert(r == 3);

    s1 = "a";
    s2 = "";
    r = s.numDistinct(s1, s2);
    assert(r == 1);

    s1 = "a";
    s2 = "ab";
    r = s.numDistinct(s1, s2);
    assert(r == 0);

    s1 = "a";
    s2 = "a";
    r = s.numDistinct(s1, s2);
    assert(r == 1);

    s1 = "a";
    s2 = "b";
    r = s.numDistinct(s1, s2);
    assert(r == 0);

    s1 = "";
    s2 = "a";
    r = s.numDistinct(s1, s2);
    assert(r == 0);
    return 0;
}
