//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

string to_str(vector<long long> s){
    ostringstream os;
    int i = 0;
    while(i<s.size()){
        os << s[i] << " ";
        i++;
    }
    os << endl;
    return os.str();
}

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

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> v;
        int sz = nums.size();
        if (sz == 0) {
            return v;
        }
        if (sz == 1) {
            v.push_back(1);
            return v;
        }

        for (int i = 0; i < sz; ++i) {
            long long prod = 1;
            for (int j = 0; j < sz; ++j) {
                if (j == i) {
                    continue;
                }
                prod *= nums[j];
            }
            v.push_back(prod);
        }

        return v;
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
    vector<int> v;
    vector<long long> r;

    int a3[] = {1, 2, 3, 4};
    v = seed_array(a3, 4);
    assert(to_str(v) == "1 2 3 4 \n");
    r = s.productExcludeItself(v);
    assert(to_str(r) == "24 12 8 6 \n");

    return 0;
}
