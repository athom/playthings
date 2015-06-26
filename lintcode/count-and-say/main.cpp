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
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        vector<string> v;
        if (n == 1) {
            return "1";
        }

        v.push_back("1");
        for (int i = 1; i < n; ++i) {
            string parsed;
            string s = v[i-1];
            char c = s[0];
            int j = 0;
            while (j < s.size()) {
                c = s[j];
                int k = 0;
                while (j < s.size() && c == s[j]) {
                    j++;
                    k++;
                }
                char buffer[10];
                sprintf(buffer,"%d",k);
                parsed.append(buffer);
                parsed.append(1, c);
            }
            v.push_back(parsed);
        }

        return v[n-1];
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
    string e;
    string r;

    r = s.countAndSay(1);
    assert(r == "1");
    r = s.countAndSay(2);
    assert(r == "11");
    r = s.countAndSay(3);
    assert(r == "21");
    r = s.countAndSay(4);
    assert(r == "1211");
    r = s.countAndSay(5);
    assert(r == "111221");
    r = s.countAndSay(6);
    assert(r == "312211");
    r = s.countAndSay(7);
    assert(r == "13112221");
    r = s.countAndSay(8);
    assert(r == "1113213211");
    r = s.countAndSay(9);
    assert(r == "31131211131221");
    r = s.countAndSay(10);
    assert(r == "13211311123113112211");


    return 0;
}
