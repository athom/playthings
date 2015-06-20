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
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        vector<int> v;
        for (vector<vector<int> >::iterator it = matrix.begin(); it != matrix.end(); it++) {
            v.insert(v.end(), (*it).begin(), (*it).end());
        }

        if (v.size() == 0 ) {
            return false;
        }

        vector<int>::iterator start;
        vector<int>::iterator mid;
        vector<int>::iterator end;
        start = v.begin();
        end = v.end() - 1;

        while (start + 1 < end) {
            mid = start + ((end - start) / 2);
            if (*mid == target) {
                return true;
            } else if (*mid < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (*start == target) {
            return true;
        }

        if (*end == target) {
            return true;
        }

        return false;
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
    vector<vector<int> > m;
    bool r;

    int a1[] = {1, 3, 5, 7};
    m.push_back(seed_array(a1, 4));
    int a2[] = {10, 11, 16, 20};
    m.push_back(seed_array(a2, 4));
    int a3[] = {23, 30, 34, 50};
    m.push_back(seed_array(a3, 4));
    r = s.searchMatrix(m, 3);
    assert(r == true);
    r = s.searchMatrix(m, 2);
    assert(r == false);

    return 0;
}
