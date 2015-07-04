//#include<>
#include<iostream>
#include <algorithm>
#include<sstream>
#include<vector>
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
    //os << endl;
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
            os << m[i][j] << ", ";
        }
    }
    return os.str();
}

struct Box {
    int sum;
    vector<vector<int> > remains;
};

string matrix_to_str2(vector<vector<Box> > m) {
    ostringstream os;
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                for (int k = 0; k < m[i][j].remains.size(); ++k) {
                    os << to_str(m[i][j].remains[k]) << ";" << endl;
                }
                continue;
            }
            for (int k = 0; k < m[i][j].remains.size(); ++k) {
                os << to_str(m[i][j].remains[k]) << ",";
            }
        }
    }
    return os.str();
}

string matrix_to_str(vector<vector<Box> > m) {
    ostringstream os;
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                os << m[i][j].sum << endl;
                continue;
            }
            os << m[i][j].sum << ", ";
        }
    }
    return os.str();
}

class Solution {
public:
    Box findRemains(vector<vector<int> > remains, int target) {
        int sz = remains.size();
        Box b;
        b.sum = 0;
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < remains[i].size(); ++j) {
                if (remains[i][j] == target) {
                    b.sum++;
                    remains[i].erase(remains[i].begin() + j);
                    b.remains.push_back(remains[i]);
                    break;
                }
            }
        }
        return b;
    }

    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        int sz = A.size();
        if (k == 0 || target == 0 || sz == 0)  {
            return 0;
        }

        // Initicalize
        vector<vector<Box> > M;
        for (int i = 0; i <= k; ++i) {
            vector<Box> boxes;
            for (int j = 0; j <= target; ++j) {
                Box b;
                b.sum = 0;
                boxes.push_back(b);
            }
            M.push_back(boxes);
        }

        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= target; ++j) {
                Box box;
                box.sum = 0;
                for (int x = 0; x < j; ++x) {
                    vector<vector<int> > remains = M[i-1][x].remains;
                    if (remains.size() == 0) {
                        remains.push_back(A);
                    }
                    if ((i-1 == 0 && x == 0) || M[i-1][x].sum > 0) {
                        Box b = findRemains(remains, j-x);
                        if (b.sum > 0) {
                            box.sum += b.sum;
                            for (int y = 0; y < b.remains.size(); ++y) {
                                bool found = false;
                                for (int z = 0; z < box.remains.size(); ++z) {
                                    if (box.remains[z] == b.remains[y]) {
                                        box.sum--;
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    box.remains.push_back(b.remains[y]);
                                }
                            }
                        }
                    }
                }
                M[i][j] = box;
            }
        }

        return M[k][target].sum;
    }
};
        //cout << matrix_to_str(M) << endl;

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
    vector<int> v;
    int r;
    int a0[] = {1, 2, 3, 4};
    v = seed_array(a0, 4);
    r = s.kSum(v, 3, 5);
    assert(r == 0);
    r = s.kSum(v, 2, 5);
    assert(r == 2);

    int a1[] = {2, 3, 5, 7};
    v = seed_array(a1, 4);
    r = s.kSum(v, 2, 5);
    assert(r == 1);
    r = s.kSum(v, 2, 7);
    assert(r == 1);

    return 0;
}
