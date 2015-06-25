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
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        string s;
        int i = a.size() - 1;
        int j = b.size() - 1;

        int incr = 0;
        for (;  i>=0 && j>=0; i--,j--) {
            s.insert(0, 1, ((a[i] == b[j]) ^ incr) ? '0' : '1');
            if (incr) {
                if (a[i] == '0' && b[j] == '0') {
                    incr = 0;
                } else {
                    incr = 1;
                }
            } else {
                if (a[i] == '1' && b[j] == '1') {
                    incr = 1;
                } else {
                    incr = 0;
                }
            }
        }
        for (;  i >= 0; i--) {
            s.insert(0, 1, ((a[i] == '1') ^ (incr == 1)) ? '1' : '0');
            incr = (a[i] == '1' && incr == 1);
        }
        for (;  j >= 0; j--) {
            s.insert(0, 1, ((b[j] == '1') ^ (incr == 1)) ? '1' : '0');
            incr = (b[j] == '1' && incr == 1);
        }
        if (incr) {
            s.insert(0, 1, '1');
        }
        return s;
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

string to_str(vector<string> v) {
    ostringstream os;

    for(int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
            os << v[i] << "\n";
            continue;
        }
        os << v[i] << ", ";
    }
    return os.str();
}

int main(int argc, char *argv[])
{
    Solution s;
    string s1;
    string s2;
    string r;

    s1 = "11";
    s2 = "1";
    r = s.addBinary(s1, s2);
    assert(r == "100");

    s1 = "11";
    s2 = "10";
    r = s.addBinary(s1, s2);
    assert(r == "101");

    s1 = "11";
    s2 = "11";
    r = s.addBinary(s1, s2);
    assert(r == "110");

    s1 = "0";
    s2 = "0";
    r = s.addBinary(s1, s2);
    assert(r == "0");

    s1 = "11110";
    s2 = "0";
    r = s.addBinary(s1, s2);
    assert(r == "11110");

    s1 = "11110";
    s2 = "1";
    r = s.addBinary(s1, s2);
    assert(r == "11111");

    s1 = "11110";
    s2 = "10";
    r = s.addBinary(s1, s2);
    assert(r == "100000");
    return 0;
}
