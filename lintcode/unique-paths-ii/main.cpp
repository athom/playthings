//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
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
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        int INF = ~(1<<31);

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        obstacleGrid[0][0] = 1;
        for (int i = 1; i < row; ++i) {
            if (obstacleGrid[i-1][0] == INF || obstacleGrid[i][0] == 1) {
                obstacleGrid[i][0] = INF;
            } else {
                obstacleGrid[i][0] = 1;
            }
        }


        for (int i = 1; i < col; ++i) {
            if (obstacleGrid[0][i-1] == INF || obstacleGrid[0][i] == 1) {
                obstacleGrid[0][i] = INF;
            } else {
                obstacleGrid[0][i] = 1;
            }
        }


        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (obstacleGrid[i-1][j] == INF && obstacleGrid[i][j-1] == INF) {
                    obstacleGrid[i][j] = INF;
                    continue;
                }
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = INF;
                    continue;
                }
                if (obstacleGrid[i-1][j] == INF) {
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                    continue;
                }
                if (obstacleGrid[i][j-1] == INF) {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j];
                    continue;
                }
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }


        if (obstacleGrid[row-1][col-1] == INF) {
            return 0;
        }


        return obstacleGrid[row-1][col-1];
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

vector<int> seed_array(const int* a, int len) {
    vector<int> v;
    for (int i = 0; i < len; i++) {
        v.push_back(a[i]);
    }

    return v;
}

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<int> > m;
    int r;

    m.clear();
    r = s.uniquePathsWithObstacles(m);
    assert(r == 0);

    m.clear();
    int a0[] = {0};
    m.push_back(seed_array(a0, 1));
    r = s.uniquePathsWithObstacles(m);
    assert(r == 1);

    m.clear();
    int a00[] = {1};
    m.push_back(seed_array(a00, 1));
    r = s.uniquePathsWithObstacles(m);
    assert(r == 0);

    m.clear();
    int a1[] = {0, 0, 0};
    m.push_back(seed_array(a1, 3));
    int a2[] = {0, 1, 0};
    m.push_back(seed_array(a2, 3));
    int a3[] = {0, 0, 0};
    m.push_back(seed_array(a3, 3));
    r = s.uniquePathsWithObstacles(m);
    assert(r == 2);

    m.clear();
    int b1[] = {0, 0, 0};
    m.push_back(seed_array(b1, 3));
    int b2[] = {0, 0, 0};
    m.push_back(seed_array(b2, 3));
    int b3[] = {0, 0, 0};
    m.push_back(seed_array(b3, 3));
    r = s.uniquePathsWithObstacles(m);
    assert(r == 6);

    m.clear();
    int c1[] = {0, 0, 0};
    m.push_back(seed_array(c1, 3));
    int c2[] = {1, 1, 0};
    m.push_back(seed_array(c2, 3));
    int c3[] = {0, 0, 0};
    m.push_back(seed_array(c3, 3));
    r = s.uniquePathsWithObstacles(m);
    assert(r == 1);

    m.clear();
    int d1[] = {0, 0, 0, 0};
    m.push_back(seed_array(d1, 4));
    int d2[] = {0, 0, 0, 0};
    m.push_back(seed_array(d2, 4));
    int d3[] = {0, 0, 0, 0};
    m.push_back(seed_array(d3, 4));
    int d4[] = {0, 0, 0, 0};
    m.push_back(seed_array(d4, 4));
    int d5[] = {0, 0, 0, 0};
    m.push_back(seed_array(d5, 4));
    int d6[] = {1, 0, 0, 0};
    m.push_back(seed_array(d6, 4));
    int d7[] = {0, 0, 0, 0};
    m.push_back(seed_array(d7, 4));
    int d8[] = {0, 0, 0, 1};
    m.push_back(seed_array(d8, 4));
    int d9[] = {0, 0, 0, 0};
    m.push_back(seed_array(d9, 4));
    int d10[] = {0, 0, 0, 1};
    m.push_back(seed_array(d10, 4));
    int d11[] = {1, 0, 0, 0};
    m.push_back(seed_array(d11, 4));
    int d12[] = {0, 0, 0, 0};
    m.push_back(seed_array(d12, 4));
    int d13[] = {0, 0, 0, 0};
    m.push_back(seed_array(d13, 4));
    int d14[] = {0, 0, 0, 0};
    m.push_back(seed_array(d14, 4));
    int d15[] = {0, 1, 1, 0};
    m.push_back(seed_array(d15, 4));
    int d16[] = {1, 0, 0, 0};
    m.push_back(seed_array(d16, 4));
    int d17[] = {0, 0, 0, 0};
    m.push_back(seed_array(d17, 4));
    r = s.uniquePathsWithObstacles(m);
    assert(r == 210);

    m.clear();
    int e1[] = {0,0,1,0,0,0};
    m.push_back(seed_array(e1, 6));
    int e2[] = {0,0,0,0,0,0};
    m.push_back(seed_array(e2, 6));
    int e3[] = {0,0,0,0,0,0};
    m.push_back(seed_array(e3, 6));
    int e4[] = {0,0,0,0,0,0};
    m.push_back(seed_array(e4, 6));
    int e5[] = {0,0,0,0,0,0};
    m.push_back(seed_array(e5, 6));
    int e6[] = {0,0,0,0,0,0};
    m.push_back(seed_array(e6, 6));
    int e7[] = {0,0,0,0,0,0};
    m.push_back(seed_array(e7, 6));

    r = s.uniquePathsWithObstacles(m);
    assert(r == 378);
    return 0;
}
