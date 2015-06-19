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
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int sz = A.size();
        if (sz == 0) {
            A.push_back(target);
            return 0;
        }

        vector<int>::iterator start;
        vector<int>::iterator mid;
        vector<int>::iterator end;
        start = A.begin();
        end = --A.end();

        while (start + 1 < end) {
            mid = start + ((end - start) / 2);

            if (*mid == target) {
                end = mid;
            } else if (*mid < target ) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (*start == target) {
            return start-A.begin();
        }
        if (*end == target) {
            return end-A.begin();
        }

        if (*start > target) {
            A.insert(start, 1, target);
            return start-A.begin();
        }

        if (*end > target) {
            A.insert(end, 1, target);
            return end-A.begin();
        }

        A.insert(end+1, 1, target);
        return end-A.begin()+1;
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

    int a1[] = {1, 1, 2, 3, 3};
    v = seed_array(a1, 5);
    assert(to_str(v) == "1 1 2 3 3 \n");
    r = s.searchInsert(v, 2);
    assert(r == 2);

    int a2[] = {1, 2, 3, 3, 4, 5, 10};
    v = seed_array(a2, 7);
    assert(to_str(v) == "1 2 3 3 4 5 10 \n");
    r = s.searchInsert(v, 3);
    assert(r == 2);

    int a3[] = {1, 2, 3, 3, 4, 5, 10};
    v = seed_array(a3, 7);
    assert(to_str(v) == "1 2 3 3 4 5 10 \n");
    r = s.searchInsert(v, 2);
    assert(r == 1);

    int a4[] = {1, 2, 3, 3, 4, 5, 10};
    v = seed_array(a4, 7);
    assert(to_str(v) == "1 2 3 3 4 5 10 \n");
    r = s.searchInsert(v, 5);
    assert(r == 5);

    int a5[] = {1, 1, 1, 1, 1,   2, 2, 2, 3, 3,  4, 5, 10};
    v = seed_array(a5, 13);
    assert(to_str(v) == "1 1 1 1 1 2 2 2 3 3 4 5 10 \n");
    r = s.searchInsert(v, 1);
    assert(r == 0);
    r = s.searchInsert(v, 2);
    assert(r == 5);
    r = s.searchInsert(v, 3);
    assert(r == 8);
    r = s.searchInsert(v, 4);
    assert(r == 10);
    r = s.searchInsert(v, 5);
    assert(r == 11);
    r = s.searchInsert(v, 10);
    assert(r == 12);


    int a6[] = {1};
    v = seed_array(a6, 1);
    assert(to_str(v) == "1 \n");
    r = s.searchInsert(v, 5);
    assert(r == 1);
    r = s.searchInsert(v, 1);
    assert(r == 0);

    int a7[] = {1, 3, 5, 6};
    v = seed_array(a7, 4);
    assert(to_str(v) == "1 3 5 6 \n");
    r = s.searchInsert(v, 5);
    assert(r == 2);
    assert(to_str(v) == "1 3 5 6 \n");
    r = s.searchInsert(v, 2);
    assert(r == 1);
    assert(to_str(v) == "1 2 3 5 6 \n");
    r = s.searchInsert(v, 7);
    assert(to_str(v) == "1 2 3 5 6 7 \n");
    assert(r == 5);
    r = s.searchInsert(v, 0);
    assert(r == 0);

    v.clear();
    r = s.searchInsert(v, 5);
    assert(r == 0);
    r = s.searchInsert(v, 1);
    assert(r == 0);
    r = s.searchInsert(v, 0);
    assert(r == 0);
    r = s.searchInsert(v, -1);
    assert(r == 0);
    r = s.searchInsert(v, 3);
    assert(r == 3);
    return 0;
}
