//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        if (A.empty() || A.size() == 1) {
            return true;
        }

        int fastest = 0;
        int i = 0;
        while (fastest < (A.size() - 1)) {
            if (A[i] == 0) {
                if (i == fastest) {
                    return false;
                }
            }
            if (i + A[i] > fastest) {
                fastest = i + A[i];
            }
            i++;
        }

        return true;
    }
};

string to_str(vector<string> v) {
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
    bool r;

    v.clear();
    int a1[] = {2, 3, 1, 1, 4};
    v = seed_array(a1, 5);
    r = s.canJump(v);
    assert(r == true);

    v.clear();
    int a2[] = {3, 2, 1, 0, 4};
    v = seed_array(a2, 5);
    r = s.canJump(v);
    assert(r == false);

    v.clear();
    int a3[] = {3};
    v = seed_array(a3, 1);
    r = s.canJump(v);
    assert(r == true);

    v.clear();
    int a4[] = {3, 2, 1, 0, 6, 3, 6};
    v = seed_array(a4, 7);
    r = s.canJump(v);
    assert(r == false);

    v.clear();
    int a5[] = {1};
    v = seed_array(a5, 1);
    r = s.canJump(v);
    assert(r == true);

    v.clear();
    int a6[] = {0};
    v = seed_array(a6, 1);
    r = s.canJump(v);
    assert(r == true);

    v.clear();
    r = s.canJump(v);
    assert(r == true);
    return 0;
}
