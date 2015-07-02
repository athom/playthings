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

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        int sz = A.size();
        if (sz == 0) {
            return 0;
        }
        if (m == 0) {
            return 0;
        }

        int sum = 0;
        for (int i = 0; i < sz; ++i) {
            sum += A[i];
        }
        if (sum <= m) {
            return sum;
        }

        sort(A.begin(), A.end());

        vector<int> S;
        vector<vector<int> > M;
        for (int i = 0; i <= m; ++i) {
            S.push_back(0);
            M.push_back(A);
        }


        for (int i = 1; i <= m; ++i) {
            int maxLoad = 0;
            int matchRow = -1;
            int matchCol = -1;
            for (int k = i-1; k >= 0; --k) {
                bool found = false;
                for (int j = 0; j < M[k].size(); ++j) {
                    int pick = S[k] + M[k][j];
                    if (pick > i) {
                        break;
                    }
                    if (pick == i) {
                        maxLoad = i;
                        matchRow = k;
                        matchCol = j;
                        found = true;
                        break;
                    }
                    if (pick < i && pick > maxLoad) {
                        maxLoad = pick;
                        matchRow = k;
                        matchCol = j;
                    }
                }
                if (found) {
                    break;
                }
            }

            if (matchRow != -1) {
                S[i] = maxLoad;
                M[i] = M[matchRow];
                M[i].erase(M[i].begin() + matchCol);
            }
        }

        return S[m];
    }
};

            //cout << "matrix: \n"<< matrix_to_str(M) << "S:" << to_str(S) << endl;


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

    int a1[] = {2, 3, 5, 7};
    v = seed_array(a1, 4);
    r = s.backPack(1, v);
    assert(r == 0);
    r = s.backPack(2, v);
    assert(r == 2);
    r = s.backPack(3, v);
    assert(r == 3);
    r = s.backPack(4, v);
    assert(r == 3);
    r = s.backPack(5, v);
    assert(r == 5);
    r = s.backPack(6, v);
    assert(r == 5);
    r = s.backPack(7, v);
    assert(r == 7);
    r = s.backPack(8, v);
    assert(r == 8);
    r = s.backPack(9, v);
    assert(r == 9);
    r = s.backPack(10, v);
    assert(r == 10);
    r = s.backPack(11, v);
    assert(r == 10);
    r = s.backPack(12, v);
    assert(r == 12);
    r = s.backPack(13, v);
    assert(r == 12);
    r = s.backPack(14, v);
    assert(r == 14);
    r = s.backPack(15, v);
    assert(r == 15);
    r = s.backPack(16, v);
    assert(r == 15);
    r = s.backPack(17, v);
    assert(r == 17);
    r = s.backPack(18, v);
    assert(r == 17);
    r = s.backPack(19, v);
    assert(r == 17);

    int a2[] = {2};
    v = seed_array(a2, 1);
    r = s.backPack(1, v);
    assert(r == 0);
    r = s.backPack(0, v);
    assert(r == 0);
    r = s.backPack(2, v);
    assert(r == 2);
    r = s.backPack(19, v);
    assert(r == 2);

    v.clear();
    r = s.backPack(19, v);
    assert(r == 0);
    return 0;
}
