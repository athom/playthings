//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }

        int** a = new int*[m];
        for (int i = 0; i < m; ++i) {
            a[i] = new int[n];
        }

        for (int i = 0; i < m; i++) {
            a[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            a[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }

        return a[m-1][n-1];
    }
};

bool ev(vector<string> v1, vector<string>v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for(int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
           return false;
        }
    }
    return true;
}

string to_str(vector<string> v) {
    ostringstream os;

    for(int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
            os << v[i] << "\n";
            continue;
        }
        os << v[i] << ", ";
    }
    return os.str();
}

int main(int argc, char *argv[])
{
    Solution s;
    int r;

    r = s.uniquePaths(1, 1);
    assert(r == 1);
    r = s.uniquePaths(1, 10);
    assert(r == 1);
    r = s.uniquePaths(10, 1);
    assert(r == 1);
    r = s.uniquePaths(2, 2);
    assert(r == 2);
    r = s.uniquePaths(2, 3);
    assert(r == 3);
    r = s.uniquePaths(2, 4);
    assert(r == 4);
    r = s.uniquePaths(3, 3);
    assert(r == 6);
    r = s.uniquePaths(3, 4);
    assert(r == 10);

    return 0;
}
