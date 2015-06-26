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
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();

        for (int i = 1; i < row; ++i) {
            grid[i][0] = grid[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < col; ++i) {
            grid[0][i] = grid[0][i-1] + grid[0][i];
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }


        return grid[row-1][col-1];
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

vector<int> seed_array(const int* a, int len) {
    vector<int> v;
    for (int i = 0; i < len; i++) {
        v.push_back(a[i]);
    }

    return v;
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

int main(int argc, char *argv[]) {
    Solution s;
    //vector<int> v;
    vector<vector<int> > m;
    int r;

    m.clear();
    r = s.minPathSum(m);
    assert(r == 0);

    m.clear();
    int a0[] = {1};
    m.push_back(seed_array(a0, 1));
    r = s.minPathSum(m);
    assert(r == 1);

    m.clear();
    int a1[] = {1, 3, 8, 4};
    m.push_back(seed_array(a1, 4));
    int a2[] = {4, 7, 5, 5};
    m.push_back(seed_array(a2, 4));
    int a3[] = {2, 6, 3, 1};
    m.push_back(seed_array(a3, 4));
    int a4[] = {8, 3, 1, 6};
    m.push_back(seed_array(a4, 4));
    r = s.minPathSum(m);
    //  1   4   12  16
    //  5   11  16  21
    //  7   13  16  17
    //  15  16  17  23
    assert(r == 23);


    return 0;
}
