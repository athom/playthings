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
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        vector<int> v;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if(A[i] < B[j]) {
                v.push_back(A[i]);
                i++;
            } else {
                v.push_back(B[j]);
                j++;
            }
        }

        while (i < m) {
            v.push_back(A[i]);
            i++;
        }
        while (j < n) {
            v.push_back(B[j]);
            j++;
        }

        for (i = 0; i < m+n; ++i) {
            A[i] = v[i];
        }
        return;
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
    int r;

    int a1[] = {1, 2, 3, -1, -1};
    int b1[] = {4, 5};
    v = seed_array(a1, 5);
    assert(to_str(v) == "1 2 3 -1 -1 \n");
    s.mergeSortedArray(a1, 3, b1, 2);
    v = seed_array(a1, 5);
    assert(to_str(v) == "1 2 3 4 5 \n");

    int a2[] = {1, 5, 7, -1, -1, -1};
    int b2[] = {4, 5, 6};
    v = seed_array(a2, 6);
    assert(to_str(v) == "1 5 7 -1 -1 -1 \n");
    s.mergeSortedArray(a2, 3, b2, 3);
    v = seed_array(a2, 6);
    assert(to_str(v) == "1 4 5 5 6 7 \n");
    return 0;
}
