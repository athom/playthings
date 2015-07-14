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
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        vector<long long> v;
        int sz = A.size();
        if (sz == 0) {
            return 0;
        }
        if (sz == 1) {
            return A[0];
        }

        for (int i = 0; i < sz; ++i) {
            v.push_back(0);
        }

        v[0] = A[0];
        v[1] = A[1] > A[0] ? A[1] : A[0];

        for (int i = 2; i < sz; ++i) {
            v[i] = max(v[i-1], v[i-2]+A[i]);
        }


        return v[sz-1];
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
    long long r;

    int a1[] = {5, 4, 1, 2, 3};
    v = seed_array(a1, 5);
    assert(to_str(v) == "5 4 1 2 3 \n");
    r = s.houseRobber(v);
    assert(r == 9);

    int a2[] = {4, 2, 4, 5, 3, 7};
    v = seed_array(a2, 6);
    assert(to_str(v) == "4 2 4 5 3 7 \n");
    r = s.houseRobber(v);
    assert(r == 16);

    int a3[] = {1, 2, 3, 4, 5, 6};
    v = seed_array(a3, 6);
    assert(to_str(v) == "1 2 3 4 5 6 \n");
    r = s.houseRobber(v);
    assert(r == 12);

    int a4[] = {6, 5, 4, 3, 2, 1};
    v = seed_array(a4, 6);
    assert(to_str(v) == "6 5 4 3 2 1 \n");
    r = s.houseRobber(v);
    assert(r == 12);

    int a5[] = {0};
    v = seed_array(a5, 1);
    assert(to_str(v) == "0 \n");
    r = s.houseRobber(v);
    assert(r == 0);

    int a6[] = {2, 3, 2, 4, 7, 9, 1};
    v = seed_array(a6, 7);
    assert(to_str(v) == "2 3 2 4 7 9 1 \n");
    r = s.houseRobber(v);
    assert(r == 16);

    int a7[] = {2, 3, 2, 2, 4, 7, 9, 1};
    v = seed_array(a7, 8);
    assert(to_str(v) == "2 3 2 2 4 7 9 1 \n");
    r = s.houseRobber(v);
    assert(r == 17);

    int a8[] = {3, 8, 4};
    v = seed_array(a8, 3);
    assert(to_str(v) == "3 8 4 \n");
    r = s.houseRobber(v);
    assert(r == 8);

    v.clear();
    r = s.houseRobber(v);
    assert(r == 0);
    return 0;
}
