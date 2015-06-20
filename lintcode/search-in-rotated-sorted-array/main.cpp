//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        if (A.size() == 0) {
            return -1;
        }
        if (A.size() == 1) {
            return A[0] == target ? 0 : -1;
        }

        vector<int>::iterator start;
        vector<int>::iterator mid;
        vector<int>::iterator end;
        start = A.begin();
        end = A.end() - 1;

        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (*mid == target) {
                return mid - A.begin();
            }

            if (*mid > *end) {
                if (target > *mid) {
                    start = mid;
                } else {
                    if (target == *start) {
                        return start - A.begin();
                    }
                    if (target > *start) {
                        end = mid;
                    } else {
                        start = mid;
                    }
                }
            } else {
                if (target > *mid) {
                    if (target == *end) {
                        return end - A.begin();
                    }
                    if (target > *end) {
                        end = mid;
                    } else {
                        start = mid;
                    }
                } else {
                    end = mid;
                }
            }

        }

        if (*start == target) {
            return start - A.begin();
        }
        if (*end == target) {
            return end - A.begin();
        }

        return -1;
    }
};

//

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

    int a1[] = {1, 2, 3, 4, 5};
    v = seed_array(a1, 5);
    assert(to_str(v) == "1 2 3 4 5 \n");
    r = s.search(v, 3);
    assert(r == 2);
    r = s.search(v, 8);
    assert(r == -1);

    int a2[] = {1};
    v = seed_array(a2, 1);
    assert(to_str(v) == "1 \n");
    r = s.search(v, 3);
    assert(r == -1);
    r = s.search(v, 1);
    assert(r == 0);

    int a3[] = {4, 5, 1, 2, 3};
    v = seed_array(a3, 5);
    assert(to_str(v) == "4 5 1 2 3 \n");
    r = s.search(v, 1);
    assert(r == 2);
    r = s.search(v, 4);
    assert(r == 0);
    r = s.search(v, 6);
    assert(r == -1);

    int a4[] = {5, 1, 2, 3, 4};
    v = seed_array(a4, 5);
    assert(to_str(v) == "5 1 2 3 4 \n");
    r = s.search(v, 6);
    assert(r == -1);
    r = s.search(v, 1);
    assert(r == 1);
    r = s.search(v, 2);
    assert(r == 2);
    r = s.search(v, 5);
    assert(r == 0);



    v.clear();
    r = s.search(v, 5);
    assert(r == -1);

    return 0;
}
