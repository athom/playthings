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
    vector<int> iBinarySearch(vector<int> &array, int start, int end, int target) {
        vector<int> r;

        if (start == end) {
            if (array[start] == target) {
                r.push_back(start);
                r.push_back(start);
                return r;
            }
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }

        int mid = (start + end) / 2;
        if (start == mid) {
            if (array[start] == target) {
                r.push_back(start);
                if (array[end] == target) {
                    r.push_back(end);
                } else {
                    r.push_back(start);
                }
                return r;
            }
            if (array[end] == target) {
                r.push_back(end);
                if (array[start] == target) {
                    r.push_back(start);
                } else {
                    r.push_back(end);
                }
                return r;
            }
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }
        if (array[mid] == target) {
            int leftExpander = mid;
            int rightExpander = mid;
            while (leftExpander >= 0 && array[leftExpander] == target) {
                leftExpander--;
            }
            while (rightExpander < array.size() && array[rightExpander] == target) {
                rightExpander++;
            }
            r.push_back(leftExpander+1);
            r.push_back(rightExpander-1);
            return r;
        }

        if (array[mid] > target) {
            return iBinarySearch(array, start, mid, target);
        }

        return iBinarySearch(array, mid, end, target);
    }

     /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &array, int target) {
        vector<int> r;

        if (array.size() == 0) {
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }
        if (array.size() == 1) {
            if (array[0] == target) {
                r.push_back(0);
                r.push_back(0);
                return r;
            }
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }

        return iBinarySearch(array, 0, array.size()-1, target);
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
    vector<int> r;

    int a1[] = {1, 1, 2, 3, 3};
    v = seed_array(a1, 5);
    assert(to_str(v) == "1 1 2 3 3 \n");
    r = s.searchRange(v, 2);
    assert(r[0] == 2);
    assert(r[1] == 2);

    int a2[] = {1, 2, 3, 3, 4, 5, 10};
    v = seed_array(a2, 7);
    assert(to_str(v) == "1 2 3 3 4 5 10 \n");
    r = s.searchRange(v, 3);
    assert(r[0] == 2);
    assert(r[1] == 3);

    int a3[] = {1, 2, 3, 3, 4, 5, 10};
    v = seed_array(a3, 7);
    assert(to_str(v) == "1 2 3 3 4 5 10 \n");
    r = s.searchRange(v, 2);
    assert(r[0] == 1);
    assert(r[1] == 1);

    int a4[] = {1, 2, 3, 3, 4, 5, 10};
    v = seed_array(a4, 7);
    assert(to_str(v) == "1 2 3 3 4 5 10 \n");
    r = s.searchRange(v, 5);
    assert(r[0] == 5);
    assert(r[1] == 5);

    int a5[] = {1, 1, 1, 1, 1,   2, 2, 2, 3, 3,  4, 5, 10};
    v = seed_array(a5, 13);
    assert(to_str(v) == "1 1 1 1 1 2 2 2 3 3 4 5 10 \n");
    r = s.searchRange(v, 1);
    assert(r[0] == 0);
    assert(r[1] == 4);
    r = s.searchRange(v, 2);
    assert(r[0] == 5);
    assert(r[1] == 7);
    r = s.searchRange(v, 3);
    assert(r[0] == 8);
    assert(r[1] == 9);
    r = s.searchRange(v, 4);
    assert(r[0] == 10);
    assert(r[1] == 10);
    r = s.searchRange(v, 5);
    assert(r[0] == 11);
    assert(r[1] == 11);
    r = s.searchRange(v, 10);
    assert(r[0] == 12);
    assert(r[1] == 12);


    int a6[] = {1};
    v = seed_array(a6, 1);
    assert(to_str(v) == "1 \n");
    r = s.searchRange(v, 5);
    assert(r[0] == -1);
    assert(r[1] == -1);
    r = s.searchRange(v, 1);
    assert(r[0] == 0);
    assert(r[1] == 0);

    v.clear();
    r = s.searchRange(v, 5);
    assert(r[0] == -1);
    assert(r[1] == -1);
    r = s.searchRange(v, 1);
    assert(r[0] == -1);
    assert(r[1] == -1);
    r = s.searchRange(v, 0);
    assert(r[0] == -1);
    assert(r[1] == -1);
    r = s.searchRange(v, -1);
    assert(r[0] == -1);
    assert(r[1] == -1);
    return 0;
}
