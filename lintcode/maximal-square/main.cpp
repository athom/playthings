//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
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
            os << m[i][j] << " ";
        }
    }
    return os.str();
}

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        int x = matrix.size();
        if (x == 0) {
            return 0;
        }
        int y = matrix[0].size();

        vector<vector<int> > m;
        for (int i = 0; i < x; ++i) {
            vector<int> v;
            for (int j = 0; j < y; ++j) {
                v.push_back(0);
            }
            m.push_back(v);
        }

        int area = 1<<31;
        for (int i = 0; i < y; ++i) {
            m[0][i] = matrix[0][i];
            if (m[0][i] > area) {
                area = m[0][i];
            }
        }
        for (int i = 0; i < x; ++i) {
            m[i][0] = matrix[i][0];
            if (m[i][0] > area) {
                area = m[i][0];
            }
        }

        for (int i = 1; i < x; ++i) {
            for (int j = 1; j < y; ++j) {
                if (m[i-1][j-1] == 0 || matrix[i][j] == 0) {
                    m[i][j] = matrix[i][j];
                    if (m[i][j] > area) {
                        area = m[i][j];
                    }
                    continue;
                }

                int step = m[i-1][j-1];
                bool match = true;
                for (int k = 1; k <= step; ++k) {
                    if (m[i-k][j] == 0) {
                        match = false;
                        break;
                    }
                }
                for (int k = 1; k <= step; ++k) {
                    if (m[i][j-k] == 0) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    m[i][j] = step+1;
                } else {
                    m[i][j] = matrix[i][j];
                }
                if (m[i][j] > area) {
                    area = m[i][j];
                }
            }
        }

        return area*area;
    }
};

string matrix_to_str(vector<vector<bool> > m) {
    ostringstream os;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                os << m[i][j] << endl;
                continue;
            }
            os << m[i][j] << " ";
        }
    }
    return os.str();
}

vector<vector<int> > seed_matrix(int* a, int x, int y) {
    vector<vector<int> > m;
    for (int i = 0; i < x; i++) {
        vector<int> v;
        for (int j = 0; j < y; j++) {
            v.push_back(*(a+y*i + j));
        }
        m.push_back(v);
    }
    return m;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int> > m;
    int r;

    int a1[2][2] = {
        {1, 0},
        {0, 1}
    };
    m = seed_matrix(*a1, 2, 2);
    assert(matrix_to_str(m) == "1 0\n0 1\n");
    r = s.maxSquare(m);
    assert(r == 1);

    int a2[5][5] = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1}
    };
    m = seed_matrix(*a2, 5, 5);
    r = s.maxSquare(m);
    assert(r == 4);


    int a3[][6] = {
        {1,1,1,1,1,1},
        {1,0,0,1,1,1},
        {1,0,1,1,1,1},
        {1,0,0,0,0,1},
        {1,1,1,1,1,1}
    };

    m = seed_matrix(*a3, 5, 6);
    r = s.maxSquare(m);
    assert(r == 9);

    int a4[][20] = {
        {1,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,1,1,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0},
        {0,0,0,1,1,1,1,0,1,0,1,1,0,0,0,0,1,0,1,0},
        {0,0,0,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1},
        {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,1,0,1},
        {0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
        {0,0,0,1,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0},
        {0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,1},
        {0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0},
        {1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0},
        {0,1,0,0,1,1,1,1,0,1,1,0,1,1,1,0,1,1,0,0},
        {1,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,1},
        {0,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,0,0,0},
        {0,0,1,1,1,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0},
        {1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,1},
        {1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0},
        {0,1,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,1,0,0},
        {0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1},
        {0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,0}
    };
    m = seed_matrix(*a4, 20, 20);
    r = s.maxSquare(m);
    assert(r == 9);

    int a5[][6] = {
        {1,1,1,1,1,1},
        {1,0,0,1,1,1},
        {1,0,1,0,1,1},
        {1,0,0,0,0,1},
        {1,1,1,1,1,1}
    };

    m = seed_matrix(*a5, 5, 6);
    r = s.maxSquare(m);
    assert(r == 4);

    return 0;
}
