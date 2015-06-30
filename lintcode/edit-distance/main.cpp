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
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        int sz1 = word1.size();
        int sz2 = word2.size();
        if (sz1 == 0) {
            return sz2;
        }
        if (sz2 == 0) {
            return sz1;
        }

        vector<vector<int> > m;
        for (int i = 0; i <= sz1; ++i) {
            vector<int> v;
            for (int i = 0; i <= sz2; ++i) {
                v.push_back(0);
            }
            m.push_back(v);
        }
        for (int i = 0; i <= sz1; ++i) {
            m[i][0] = i;
        }
        for (int i = 0; i <= sz2; ++i) {
            m[0][i] = i;
        }

        for (int i = 1; i <= sz1; ++i) {
            for (int j = 1; j <= sz2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    m[i][j] = m[i-1][j-1];
                } else {
                    m[i][j] = min(m[i-1][j-1], min(m[i-1][j], m[i][j-1])) + 1;
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
    r = s.minDistance(s1, s2);
    assert(r == 1);

    s1 = "mart";
    s2 = "karma";
    r = s.minDistance(s1, s2);
    assert(r == 3);

    s1 = "";
    s2 = "";
    r = s.minDistance(s1, s2);
    assert(r == 0);

    s1 = "";
    s2 = "mario tooki";
    r = s.minDistance(s1, s2);
    assert(r == 11);

    s1 = "super star";
    s2 = "super star";
    r = s.minDistance(s1, s2);
    assert(r == 0);

    s1 = "super star";
    s2 = "super start";
    r = s.minDistance(s1, s2);
    assert(r == 1);

    s1 = "tsuper star";
    s2 = "super start";
    r = s.minDistance(s1, s2);
    assert(r == 2);

    return 0;
}
