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
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }
        int row = triangle.size();
        for (int i = row -2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
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
    vector<vector<int> > m;
    int r;

    m.clear();
    r = s.minimumTotal(m);
    assert(r == 0);

    m.clear();
    int a0[] = {1};
    m.push_back(seed_array(a0, 1));
    r = s.minimumTotal(m);
    assert(r == 1);

    m.clear();
    int a1[] = {2};
    m.push_back(seed_array(a1, 1));
    int a2[] = {3, 4};
    m.push_back(seed_array(a2, 2));
    int a3[] = {6, 5, 7};
    m.push_back(seed_array(a3, 3));
    int a4[] = {4, 1, 8, 3};
    m.push_back(seed_array(a4, 4));
    r = s.minimumTotal(m);
    //  2
    //  3   4
    //  6   5   7
    //  4   1   8   3
    assert(r == 11);

    return 0;
}
