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
    int iBinarySearch(vector<int> &array, int start, int end, int target) {
        if (start == end) {
            return array[start] == target ? start : -1;
        }

        int mid = (start + end) / 2;
        if (start == mid) {
            if (array[start] == target) {
                return start;
            }
            if (array[end] == target) {
                return end;
            }
            return -1;
        }
        if (array[mid] == target) {
            while(mid >= 0 && array[mid] == target) {
                mid--;
            }
            return mid+1;
        }

        if (array[mid] > target) {
            return iBinarySearch(array, start, mid, target);
        }

        return iBinarySearch(array, mid, end, target);
    }

    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        if (array.size() == 0) {
            return -1;
        }
        if (array.size() == 1) {
            return array[0] == target ? 0 : -1;
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
    int r;

    int a1[] = {1, 1, 2, 3, 3};
    v = seed_array(a1, 5);
    assert(to_str(v) == "1 1 2 3 3 \n");
    r = s.binarySearch(v, 2);
    assert(r == 2);

    int a2[] = {1, 2, 3, 3, 4, 5, 10};
    v = seed_array(a2, 7);
    assert(to_str(v) == "1 2 3 3 4 5 10 \n");
    r = s.binarySearch(v, 3);
    assert(r == 2);

    int a3[] = {1, 2, 3, 3, 4, 5, 10};
    v = seed_array(a3, 7);
    assert(to_str(v) == "1 2 3 3 4 5 10 \n");
    r = s.binarySearch(v, 2);
    assert(r == 1);

    int a4[] = {1, 2, 3, 3, 4, 5, 10};
    v = seed_array(a4, 7);
    assert(to_str(v) == "1 2 3 3 4 5 10 \n");
    r = s.binarySearch(v, 5);
    assert(r == 5);

    int a5[] = {1, 1, 1, 1, 1,   2, 2, 2, 3, 3,  4, 5, 10};
    v = seed_array(a5, 13);
    assert(to_str(v) == "1 1 1 1 1 2 2 2 3 3 4 5 10 \n");
    r = s.binarySearch(v, 1);
    assert(r == 0);
    r = s.binarySearch(v, 2);
    assert(r == 5);
    r = s.binarySearch(v, 3);
    assert(r == 8);
    r = s.binarySearch(v, 4);
    assert(r == 10);
    r = s.binarySearch(v, 5);
    assert(r == 11);
    r = s.binarySearch(v, 10);
    assert(r == 12);


    int a6[] = {1};
    v = seed_array(a6, 1);
    assert(to_str(v) == "1 \n");
    r = s.binarySearch(v, 5);
    assert(r == -1);
    r = s.binarySearch(v, 1);
    assert(r == 0);

    v.clear();
    r = s.binarySearch(v, 5);
    assert(r == -1);
    r = s.binarySearch(v, 1);
    assert(r == -1);
    r = s.binarySearch(v, 0);
    assert(r == -1);
    r = s.binarySearch(v, -1);
    assert(r == -1);
    return 0;
}
