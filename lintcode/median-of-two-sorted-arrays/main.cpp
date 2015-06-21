//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <cmath>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        vector<int> C;
        int i = 0;
        int j = 0;

        while (i < A.size() && j < B.size()) {
            while (i < A.size() && j < B.size() && A[i] <= B[j]) {
                C.push_back(A[i]);
                i++;
            }
            while (i < A.size() && j < B.size() && A[i] > B[j]) {
                C.push_back(B[j]);
                j++;
            }
        }

        while (i < A.size()) {
            C.push_back(A[i]);
            i++;
        }
        while (j < B.size()) {
            C.push_back(B[j]);
            j++;
        }

        int sz = C.size();
        if (sz == 0) {
            return 0;
        }
        if (sz % 2 == 0) {
            return (C[sz/2-1] + C[sz/2]) / 2.0;
        }

        return C[sz/2];
    }
};

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

vector<int> seed_array(const int* a, int len) {
    vector<int> v;
    for (int i = 0; i < len; i++) {
        v.push_back(a[i]);
    }

    return v;
}

bool de(double i, double e) {
    return abs(i-e) < 0.0000000001;
}

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v1;
    vector<int> v2;
    double r;

    int a1[] = {1, 2, 3};
    int b1[] = {4, 5};
    v1 = seed_array(a1, 3);
    v2 = seed_array(b1, 2);
    r = s.findMedianSortedArrays(v1, v2);
    assert(de(r, 3));

    int a2[] = {1, 2, 3, 4, 5, 6};
    int b2[] = {2, 3, 4, 5};
    v1 = seed_array(a2, 6);
    v2 = seed_array(b2, 4);
    r = s.findMedianSortedArrays(v1, v2);
    assert(de(r, 3.5));

    v2.clear();
    r = s.findMedianSortedArrays(v1, v2);
    assert(de(r, 3.5));

    v1.clear();
    int b0[] = {2, 3, 4, 5, 6};
    v2 = seed_array(b0, 5);
    r = s.findMedianSortedArrays(v1, v2);
    assert(de(r, 4));

    v1.clear();
    int b00[] = {2, 3, 4, 5};
    v2 = seed_array(b00, 4);
    r = s.findMedianSortedArrays(v1, v2);
    assert(de(r, 3.5));

    v1.clear();
    v2.clear();
    r = s.findMedianSortedArrays(v1, v2);
    assert(de(r, 0));
    return 0;
}
