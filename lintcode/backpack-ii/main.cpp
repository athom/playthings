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

struct Box {
    int size;
    int value;
    int sum;
};

string matrix_to_str(vector<vector<Box> > m) {
    ostringstream os;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                os << m[i][j].size << endl;
                continue;
            }
            os << m[i][j].size << ", ";
        }
    }
    return os.str();
}

string to_str(vector<Box> s){
    ostringstream os;
    int i = 0;
    while(i<s.size()){
        os << "(" <<s[i].size << ", " << s[i].value << ") ";
        i++;
    }
    os << endl;
    return os.str();
}

struct Less {
    bool operator()(Box a, Box b) {
        return a.size < b.size;
    }
};

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        if (m == 0) {
            return 0;
        }
        int szA = A.size();
        int szV = V.size();
        if (szA == 0 || szV == 0) {
            return 0;
        }

        vector<Box> B;
        for (int i = 0; i < szA; ++i) {
            Box b;
            b.size = A[i];
            b.value = V[i];
            b.sum = b.size * b.value;
            B.push_back(b);
        }

        Less less;
        sort(B.begin(), B.end(), less);

        vector<Box> F;
        vector<vector<Box> > M;
        for (int i = 0; i <= m; ++i) {
            Box b;
            b.size = 0;
            b.value = 0;
            b.sum = 0;
            F.push_back(b);
            M.push_back(B);
        }
        for (int i = 1; i <= m; ++i) {
            int maxValue = F[i-1].value;
            int newSize = F[i-1].size;
            int bestRow = i-1;
            int pickIndex = -1;
            for (int j = i-1; j >= 0; j--) {
                Box b = F[j];
                vector<Box> remains = M[j];
                for (int k = 0; k < remains.size(); ++k) {
                    if (remains[k].size + b.size > i) {
                        break;
                    }
                    if (remains[k].value + b.value > maxValue) {
                        maxValue = remains[k].value + b.value;
                        newSize = b.size + remains[k].size;
                        pickIndex = k;
                        bestRow = j;
                    }
                }
            }
            if (pickIndex == -1) {
                F[i] = F[i-1];
                M[i] = M[i-1];
            } else {
                F[i] = F[bestRow];
                F[i].value = maxValue;
                F[i].size = newSize;
                M[i] = M[bestRow];
                M[i].erase(M[i].begin() + pickIndex);
            }
        }

        return F[m].value;
    }
};

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
    vector<int> A;
    vector<int> V;
    int r;

    int a0[] = {2, 3, 5, 7};
    int v0[] = {1, 5, 2, 4};
    A = seed_array(a0, 4);
    V = seed_array(v0, 4);
    r = s.backPackII(0, A, V);
    assert(r == 0);
    r = s.backPackII(1, A, V);
    assert(r == 0);
    r = s.backPackII(2, A, V);
    assert(r == 1);
    r = s.backPackII(3, A, V);
    assert(r == 5);
    r = s.backPackII(4, A, V);
    assert(r == 5);
    r = s.backPackII(5, A, V);
    assert(r == 6);
    r = s.backPackII(6, A, V);
    assert(r == 6);
    r = s.backPackII(7, A, V);
    assert(r == 6);
    r = s.backPackII(8, A, V);
    assert(r == 7);
    r = s.backPackII(9, A, V);
    assert(r == 7);
    r = s.backPackII(10,A,  V);
    assert(r == 9);
    r = s.backPackII(11,A,  V);
    assert(r == 9);
    r = s.backPackII(12,A,  V);
    assert(r == 10);
    r = s.backPackII(13,A,  V);
    assert(r == 10);
    r = s.backPackII(14,A,  V);
    assert(r == 10);
    r = s.backPackII(15,A,  V);
    assert(r == 11);
    r = s.backPackII(16,A,  V);
    assert(r == 11);
    r = s.backPackII(17,A,  V);
    assert(r == 12);
    r = s.backPackII(18, A, V);
    assert(r == 12);
    r = s.backPackII(19, A, V);
    assert(r == 12);
    return 0;

    int a1[] = {2, 3, 5, 7};
    int v1[] = {1, 5, 4, 2};
    A = seed_array(a1, 4);
    V = seed_array(v1, 4);
    r = s.backPackII(0, A, V);
    assert(r == 0);
    r = s.backPackII(1, A, V);
    assert(r == 0);
    r = s.backPackII(2, A, V);
    assert(r == 1);
    r = s.backPackII(3, A, V);
    assert(r == 5);
    r = s.backPackII(4, A, V);
    assert(r == 5);
    r = s.backPackII(5, A, V);
    assert(r == 6);
    r = s.backPackII(6, A, V);
    assert(r == 6);
    r = s.backPackII(7, A, V);
    assert(r == 6);
    r = s.backPackII(8, A, V);
    assert(r == 9);
    r = s.backPackII(9, A, V);
    assert(r == 9);
    r = s.backPackII(10,A,  V);
    assert(r == 10);
    r = s.backPackII(11,A,  V);
    assert(r == 10);
    r = s.backPackII(12,A,  V);
    assert(r == 10);
    r = s.backPackII(13,A,  V);
    assert(r == 10);
    r = s.backPackII(14,A,  V);
    assert(r == 10);
    r = s.backPackII(15,A,  V);
    assert(r == 11);
    r = s.backPackII(16,A,  V);
    assert(r == 11);
    r = s.backPackII(17,A,  V);
    assert(r == 12);
    r = s.backPackII(18, A, V);
    assert(r == 12);
    r = s.backPackII(19, A, V);
    assert(r == 12);

    int a2[] = {2};
    int v2[] = {3};
    A = seed_array(a2, 1);
    V = seed_array(v2, 1);
    r = s.backPackII(0, A, V);
    assert(r == 0);
    r = s.backPackII(1, A, V);
    assert(r == 0);
    r = s.backPackII(2, A, V);
    assert(r == 3);
    r = s.backPackII(19, A, V);
    assert(r == 3);

    A.clear();
    V.clear();
    r = s.backPackII(19, A, V);
    assert(r == 0);
    return 0;
}
