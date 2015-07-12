//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

string to_str(vector<int> s){
    ostringstream os;
    int i = 0;
    while(i<s.size()){
        os << s[i] << " ";
        i++;
    }
    os << endl;
    return os.str();
}

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
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        vector<int> v;
        int x = matrix.size();
        if (x == 0) {
            return v;
        }
        int y = matrix[0].size();

        for (int i = 0; i < x + y; ++i) {
            if (i % 2 == 0) {
                for (int k = i; k >=0; k--) {
                    if (k >= x || i-k >= y) {
                        continue;
                    }
                    v.push_back(matrix[k][i-k]);
                }
            } else {
                for (int k = 0; k <= i; k++) {
                    if (k >= x || i-k >= y) {
                        continue;
                    }
                    v.push_back(matrix[k][i-k]);
                }
            }
        }

        return v;
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
    vector<int> r;

    int a4[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    m = seed_matrix(*a4, 3, 4);
    r = s.printZMatrix(m);
    assert(to_str(r) == "1 2 5 9 6 3 4 7 10 11 8 12 \n");

    int a1[2][2] = {
        {1, 0},
        {0, 1}
    };
    m = seed_matrix(*a1, 2, 2);
    assert(matrix_to_str(m) == "1 0\n0 1\n");
    r = s.printZMatrix(m);
    assert(to_str(r) == "1 0 0 1 \n");

    int a2[5][5] = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1}
    };
    m = seed_matrix(*a2, 5, 5);
    assert(matrix_to_str(m) == "1 1 0 0 0\n0 1 0 0 1\n0 0 0 1 1\n0 0 0 0 0\n0 0 0 0 1\n");
    r = s.printZMatrix(m);
    assert(to_str(r) == "1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 1 \n");


    int a3[][6] = {
        {1,1,1,1,1,1},
        {1,0,0,0,0,1},
        {1,0,1,1,0,1},
        {1,0,0,0,0,1},
        {1,1,1,1,1,1}
    };
    m = seed_matrix(*a3, 5, 6);
    assert(matrix_to_str(m) == "1 1 1 1 1 1\n1 0 0 0 0 1\n1 0 1 1 0 1\n1 0 0 0 0 1\n1 1 1 1 1 1\n");
    r = s.printZMatrix(m);
    assert(to_str(r) == "1 1 1 1 0 1 1 0 0 1 1 0 1 0 1 1 0 1 0 1 1 0 0 1 1 0 1 1 1 1 \n");


    return 0;
}
