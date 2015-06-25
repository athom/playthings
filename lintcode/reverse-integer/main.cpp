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
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        if (n == 0) {
            return 0;
        }
        long long m = 0;
        int i = 1;
        while (n) {
            int r = n%10;
            m = m*10 + r;
            n = n / (10*i);
        }

        if (m > ~(1<<31) || m < (1 << 31)) {
            return 0;
        }
        return m;
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
    int r;

    r = s.reverseInteger(123);
    assert(r == 321);

    r = s.reverseInteger(-123);
    assert(r == -321);

    r = s.reverseInteger(0);
    assert(r == 0);

    r = s.reverseInteger(0);
    assert(r == 0);

    r = s.reverseInteger(333);
    assert(r == 333);
    r = s.reverseInteger(-333);
    assert(r == -333);

    r = s.reverseInteger(2147483647);
    assert(r == 0);
    r = s.reverseInteger(-2147483647);
    assert(r == 0);
    return 0;
}
