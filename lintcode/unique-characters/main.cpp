//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <set>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        set<int> e;
        for (int i = 0; i < str.size(); ++i) {
            e.insert(int(str[i]));
        }
        return e.size() == str.size();
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    string ss;
    bool r;

    ss = "abc";
    r = s.isUnique(ss);
    assert(r == true);

    ss = "";
    r = s.isUnique(ss);
    assert(r == true);

    ss = "a";
    r = s.isUnique(ss);
    assert(r == true);

    ss = "aabc";
    r = s.isUnique(ss);
    assert(r == false);

    ss = "aa";
    r = s.isUnique(ss);
    assert(r == false);
    return 0;
}
