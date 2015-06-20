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
    void recoverRotatedSortedArray(vector<int> &nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }

        vector<int>::iterator start;
        vector<int>::iterator mid;
        vector<int>::iterator end;
        vector<int>::iterator pos;

        start = nums.begin();
        end = nums.end() - 1;

        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (*mid == *end) {
                start = mid;
            } else if (*mid > *end) {
                start = mid;
            } else {
                end = mid;
            }
        }

        int minVal = 0;
        if (*start <= *end) {
            minVal = *start;
            pos = start;
        } else {
            minVal = *end;
            pos = end;
        }


        vector<int>::iterator left1;
        vector<int>::iterator right1;
        vector<int>::iterator left2;
        vector<int>::iterator right2;
        left1 = nums.begin();
        right1 = pos - 1;
        left2 = pos;
        right2 = nums.end() - 1;

        while (left1 < right1) {
            int tmp = *right1;
            *right1 = *left1;
            *left1 = tmp;

            left1++;
            right1--;
        }
        while (left2 < right2) {
            int tmp = *right2;
            *right2 = *left2;
            *left2 = tmp;

            left2++;
            right2--;
        }

        vector<int>::iterator left;
        vector<int>::iterator right;
        left = nums.begin();
        right = nums.end() - 1;
        while (left < right) {
            int tmp = *right;
            *right = *left;
            *left = tmp;

            left++;
            right--;
        }
    }
};

//3, 3, 3, 1, 2, 3

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
    s.recoverRotatedSortedArray(v);
    assert(to_str(v) == "1 2 3 4 5 \n");

    int a2[] = {1};
    v = seed_array(a2, 1);
    assert(to_str(v) == "1 \n");
    s.recoverRotatedSortedArray(v);
    assert(to_str(v) == "1 \n");

    int a3[] = {4, 5, 1, 2, 3};
    v = seed_array(a3, 5);
    assert(to_str(v) == "4 5 1 2 3 \n");
    s.recoverRotatedSortedArray(v);
    assert(to_str(v) == "1 2 3 4 5 \n");

    int a4[] = {5, 1, 2, 3, 4};
    v = seed_array(a4, 5);
    assert(to_str(v) == "5 1 2 3 4 \n");
    s.recoverRotatedSortedArray(v);
    assert(to_str(v) == "1 2 3 4 5 \n");

    int a5[] = {5, 5, 1, 1, 2, 3, 4};
    v = seed_array(a5, 7);
    assert(to_str(v) == "5 5 1 1 2 3 4 \n");
    s.recoverRotatedSortedArray(v);
    assert(to_str(v) == "1 1 2 3 4 5 5 \n");

    v.clear();
    s.recoverRotatedSortedArray(v);
    assert(v.empty());

    return 0;
}
