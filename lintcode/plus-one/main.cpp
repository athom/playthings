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
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0) {
            if (digits[i] + 1 < 10) {
                digits[i] = digits[i] + 1;
                return digits;
            }
            digits[i] = 0;
            i--;
        }

        if (i < 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

bool ev(vector<string> v1, vector<string>v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for(int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
           return false;
        }
    }
    return true;
}

//string to_str(vector<string> v) {
    //ostringstream os;

    //for(int i = 0; i < v.size(); i++) {
        //if (i == v.size() - 1) {
            //os << v[i] << "\n";
            //continue;
        //}
        //os << v[i] << ", ";
    //}
    //return os.str();
//}
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

    int a1[] = {1, 2, 1, 3, 4, 5, 7, 6};
    v = seed_array(a1, 8);
    assert(to_str(v) == "1 2 1 3 4 5 7 6 \n");
    v = s.plusOne(v);
    assert(to_str(v) == "1 2 1 3 4 5 7 7 \n");

    int a2[] = {1, 2, 1, 3, 4, 5, 7, 9};
    v = seed_array(a2, 8);
    assert(to_str(v) == "1 2 1 3 4 5 7 9 \n");
    v = s.plusOne(v);
    assert(to_str(v) == "1 2 1 3 4 5 8 0 \n");

    int a3[] = {9, 9, 9};
    v = seed_array(a3, 3);
    assert(to_str(v) == "9 9 9 \n");
    v = s.plusOne(v);
    assert(to_str(v) == "1 0 0 0 \n");

    int a4[] = {1};
    v = seed_array(a4, 1);
    assert(to_str(v) == "1 \n");
    v = s.plusOne(v);
    assert(to_str(v) == "2 \n");
    return 0;
}
