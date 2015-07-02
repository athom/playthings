//#include<>
#include<iostream>
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
            os << m[i][j] << ", ";
        }
    }
    return os.str();
}

struct E {
    int Value;
    int Left;
    int Right;
};

string matrix_to_str(vector<vector<E> > m) {
    ostringstream os;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size() - i; j++) {
            if (j == m[i].size() - i - 1) {
                os << m[i][j].Value << ":" << "(" <<m[i][j].Left << "," << m[i][j].Right << ")" << endl << endl;
                continue;
            }
            os << m[i][j].Value << ": " << "(" <<m[i][j].Left << "," << m[i][j].Right << ")" << "\t";
        }
    }
    return os.str();
}

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        int sz = A.size();
        if (sz == 0 || sz == 1) {
            return 0;
        }
        int N = 100;
        int INF = ~(1<<31);

        vector<vector<int> > M;
        for (int i = 0; i <= sz; ++i) {
            vector<int> V;
            for (int j = 0; j <= N; ++j) {
                V.push_back(0);
            }
            M.push_back(V);
        }

        for (int i = 0; i <= N; ++i) {
            M[0][i] = abs(A[0] - i);
        }

        for (int i = 1; i <= sz; ++i) {
            for (int j = 0; j <= N; ++j) {
                int start = j - target;
                if (start < 0) {
                    start = 0;
                }
                int stop = j + target;
                if (stop > N) {
                    stop = N;
                }
                int minSum = INF;
                for (int k = start; k <= stop; ++k) {
                    if (M[i-1][k] + abs(A[i] - j) < minSum) {
                        minSum = M[i-1][k] + abs(A[i] - j);
                    }
                }
                M[i][j] = minSum;
            }
        }

        int r = INF;
        for (int i = 0; i <= N; ++i) {
            if (M[sz-1][i] < r) {
                r = M[sz-1][i];
            }
        }
        return r;
    }
};

// 1 4 2 3
// s[0] = 0
// m[0] = []
// s[1] = 0
// m[1] = [1]
// s[2] = 2
// m[2] = [2, 3]

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

    int a4[] = {1, 4, 7, 3};
    v = seed_array(a4, 4);
    r = s.MinAdjustmentCost(v, 1);
    assert(r == 5);

    int a6[] = {1,1,1,1,1, 1,1,1,1,1, 1,1,1};
    v = seed_array(a6, 13);
    r = s.MinAdjustmentCost(v, 1);
    assert(r == 0);

    int a7[] = {1,100,2,99,3,   98,4,97,5,96,   1,10,15,16,19,  10,1,2,3,4, 95};
    v = seed_array(a7, 21);
    r = s.MinAdjustmentCost(v, 79);
    assert(r == 96);

    int a8[] = {51,62,81,14,15, 39,63,38,48,94, 42,91,91,81,91, 40,67,66,82,16};
    v = seed_array(a8, 20);
    r = s.MinAdjustmentCost(v, 20);
    assert(r == 188);

    int a5[] = {12,3,7,4,5,13,2,8,4,7,6,5,7};
    v = seed_array(a5, 13);
    r = s.MinAdjustmentCost(v, 2);
    assert(r == 19);


    int a3[] = {20,25,35,45,55, 65,75,85,25,35, 45,55,15,15,15, 7,2,11,15,11, 15};
                                    //65 55 45     35 25
                                    //20 30 10     20 10
    v = seed_array(a3, 21);
    r = s.MinAdjustmentCost(v, 10);
    assert(r == 90);

    int a0[] = {1, 4, 7, 3};
    v = seed_array(a0, 4);
    r = s.MinAdjustmentCost(v, 1);
    assert(r == 5);


    int a1[] = {1, 4, 2, 3};
    v = seed_array(a1, 4);
    r = s.MinAdjustmentCost(v, 1);
    assert(r == 2);

    int a2[] = {1, 4, 7};
    v = seed_array(a2, 3);
    r = s.MinAdjustmentCost(v, 1);
    assert(r == 4);


    v.clear();
    r = s.MinAdjustmentCost(v, 1);
    assert(r == 0);

    v.clear();
    v.push_back(41);
    r = s.MinAdjustmentCost(v, 1);
    assert(r == 0);
    return 0;
}
