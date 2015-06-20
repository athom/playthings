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
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        if (A.size() < 3) {
            return -1;
        }


        vector<int>::iterator start;
        vector<int>::iterator mid;
        vector<int>::iterator end;
        vector<int>::iterator pre;
        vector<int>::iterator next;

        start = A.begin();
        end = A.end() - 1;

        while (start + 1 < end) {
            mid = start + ((end - start) / 2);
            pre = mid - 1;
            next = mid + 1;

            if ((*pre < *mid) && (*mid > *next)) {
                return mid - A.begin();
            } else if ((*pre < *mid) && (*mid < *next)) {
                start = mid;
            } else if ((*pre > *mid) && (*mid > *next)) {
                end = mid;
            } else if ((*pre > *mid) && (*mid < *next)) {
                end = mid;
            }
        }

        return 0;
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

    int a1[] = {1, 2, 1, 3, 4, 5, 7, 6};
    v = seed_array(a1, 8);
    assert(to_str(v) == "1 2 1 3 4 5 7 6 \n");
    r = s.findPeak(v);
    if (r == 1) {
        assert(r == 1);
    } else {
        assert(r == 6);
    }

    int a2[] = {1, 2, 1};
    v = seed_array(a2, 3);
    assert(to_str(v) == "1 2 1 \n");
    r = s.findPeak(v);
    assert(r == 1);

    int a3[] = {100,102,104,7,9,11,4,3};
    v = seed_array(a3, 8);
    assert(to_str(v) == "100 102 104 7 9 11 4 3 \n");
    r = s.findPeak(v);
    if (r == 2) {
        assert(r == 2);
    } else {
        assert(r == 5);
    }


    return 0;
}
