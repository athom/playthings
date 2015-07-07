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
    int largestRectangleAreaHelper(vector<int> &height, int left, int right) {
        if (right - left < 0) {
            return 0;
        }

        int INF = ~(1<<31);
        int min = INF;
        int minIndex = -1;
        for (int i = left; i <= right; ++i) {
            if (height[i] < min) {
                min = height[i];
                minIndex = i;
            }
        }

        int area = -INF;
        int midArea = min * (right-left+1);
        int newRight = minIndex-1;
        int newLeft = minIndex+1;

        int leftArea = largestRectangleAreaHelper(height, left, newRight);
        int rightArea = largestRectangleAreaHelper(height, newLeft, right);


        if (midArea > area) {
            area = midArea;
        }
        if (leftArea > area) {
            area = leftArea;
        }
        if (rightArea > area) {
            area = rightArea;
        }
        return area;
    }
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        int sz = height.size();
        if (sz == 0) {
            return 0;
        }

        return largestRectangleAreaHelper(height, 0, sz-1);
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

    int a1[] = {1, 2, 3, 2, 2};
    v = seed_array(a1, 5);
    assert(to_str(v) == "1 2 3 2 2 \n");
    r = s.largestRectangleArea(v);
    assert(r == 8);

    int a2[] = {1, 2, 3, 4, 5};
    v = seed_array(a2, 5);
    assert(to_str(v) == "1 2 3 4 5 \n");
    r = s.largestRectangleArea(v);
    assert(r == 9);

    int a3[] = {1, 1, 2, 1};
    v = seed_array(a3, 4);
    assert(to_str(v) == "1 1 2 1 \n");
    r = s.largestRectangleArea(v);
    assert(r == 4);

    int a4[] = {1, 1};
    v = seed_array(a4, 2);
    assert(to_str(v) == "1 1 \n");
    r = s.largestRectangleArea(v);
    assert(r == 2);



    int a7[] = {2, 1, 5, 6, 2, 3};
    v = seed_array(a7, 6);
    r = s.largestRectangleArea(v);
    assert(r == 10);


    v.clear();
    r = s.largestRectangleArea(v);
    assert(r == 0);
    return 0;
}
