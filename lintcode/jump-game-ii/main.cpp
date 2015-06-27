//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

string to_str(vector<int> v) {
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

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    //// From right to left;
    //int jump(vector<int> A) {
        //int sz = A.size();
        //if (sz == 0 || sz == 1) {
            //return 0;
        //}
        //int INF = ~(1<<31);

        //A[sz - 1] = 0;
        //for (int i = sz - 2; i >= 0; --i) {
            //int toWalkSteps = A[i];
            //int walkedSteps = INF;
            //for (int j = 1; i + j < sz && j <= toWalkSteps; ++j) {
                //if (A[i+j] == 0 && i+j != sz -1) {
                    //continue;
                //}
                //if (A[i+j] < walkedSteps) {
                    //walkedSteps = A[i+j];
                //}
            //}
            //if (walkedSteps == INF) {
                //A[i] = 0;
            //} else {
                //A[i] = walkedSteps + 1;
            //}
        //}

        //return A[0];
    //}

    // From left to right
    int jump(vector<int> A) {
        int sz = A.size();
        if (sz == 0 || sz == 1) {
            return 0;
        }
        int INF = ~(1<<31);

        vector<int> W;
        W.push_back(0);
        for (int i = 1; i < sz; ++i) {
            W.push_back(INF);
            for (int j = 0; j < i; ++j) {
                if (W[j] != INF && A[j] + j >= i) {
                    W[i] = W[j] + 1;
                    break;
                }
            }
        }

        if (W[sz-1] == INF) {
            return 0;
        }
        return W[sz-1];
    }
};


vector<int> seed_array(const int* a, int len) {
    vector<int> v;
    for (int i = 0; i < len; i++) {
        v.push_back(a[i]);
    }
    return v;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v;
    int r;

    v.clear();
    int a1[] = {2, 3, 1, 1, 4};
    v = seed_array(a1, 5);
    r = s.jump(v);
    assert(r == 2);

    v.clear();
    int a2[] = {3, 2, 1, 0, 4};
    v = seed_array(a2, 5);
    r = s.jump(v);
    assert(r == 0);

    v.clear();
    int a3[] = {3};
    v = seed_array(a3, 1);
    r = s.jump(v);
    assert(r == 0);

    v.clear();
    int a4[] = {3, 2, 1, 0, 6, 3, 6};
    v = seed_array(a4, 7);
    r = s.jump(v);
    assert(r == 0);

    v.clear();
    int a5[] = {1};
    v = seed_array(a5, 1);
    r = s.jump(v);
    assert(r == 0);

    v.clear();
    int a6[] = {0};
    v = seed_array(a6, 1);
    r = s.jump(v);
    assert(r == 0);

    v.clear();
    int a8[] = {13,52,42,21,58};
    v = seed_array(a8, 5);
    r = s.jump(v);
    assert(r == 1);

    v.clear();
    r = s.jump(v);
    assert(r == 0);
    return 0;
}
