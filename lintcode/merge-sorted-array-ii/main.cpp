//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int szA = A.size();
        int szB = B.size();
        if (szA == 0) {
            return B;
        }
        if (szB == 0) {
            return A;
        }

        vector<int> v;

        int i = 0;
        int j = 0;
        while (i < szA && j < szB) {
            if (A[i] <= B[j]) {
                v.push_back(A[i]);
                i++;
                continue;
            } else {
                v.push_back(B[j]);
                j++;
            }
        }

        while (i < szA) {
            v.push_back(A[i]);
            i++;
        }
        while (j < szB) {
            v.push_back(B[j]);
            j++;
        }

        return v;
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

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v;
    vector<int> v1;
    vector<int> v2;

    v1.clear();
    v2.clear();
    v = s.mergeSortedArray(v1, v2);
    assert(v.size() == 0);

    int a1[] = {1, 2, 3};
    int b1[] = {4, 5};
    v1 = seed_array(a1, 3);
    v2 = seed_array(b1, 2);
    v = s.mergeSortedArray(v1, v2);
    assert(to_str(v) == "1 2 3 4 5 \n");

    int a2[] = {1, 5, 7};
    int b2[] = {4, 5, 6};
    v1 = seed_array(a2, 3);
    v2 = seed_array(b2, 3);
    v = s.mergeSortedArray(v1, v2);
    assert(to_str(v) == "1 4 5 5 6 7 \n");
    return 0;
}
