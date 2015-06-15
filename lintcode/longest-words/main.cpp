//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> v;
        for (vector<string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
            string curStr = *it;
            if (v.empty()) {
                v.push_back(curStr);
                continue;
            }

            if (v[0].size() < (curStr).size()) {
                v.clear();
                v.push_back(curStr);
                continue;
            }

            if (v[0].size() == curStr.size()) {
                v.push_back(curStr);
            }
        }
        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> v;

    v.clear();
    v.push_back("dog");
    v.push_back("google");
    v.push_back("facebook");
    v.push_back("internaltional");
    v.push_back("blabla");
    v = s.longestWords(v);
    assert(v.size() == 1);
    assert(v[0] == "internaltional");


    v.clear();
    v = s.longestWords(v);
    assert(v.size() == 0);


    v.clear();
    v.push_back("1");
    v.push_back("22");
    v.push_back("234");
    v.push_back("34");
    v = s.longestWords(v);
    assert(v.size() == 1);
    assert(v[0] == "234");

    v.clear();
    v.push_back("1");
    v.push_back("223");
    v.push_back("234");
    v.push_back("34");
    v = s.longestWords(v);
    assert(v.size() == 2);
    assert(v[0] == "223");
    assert(v[1] == "234");


    v.clear();
    v.push_back("1");
    v = s.longestWords(v);
    assert(v.size() == 1);
    assert(v[0] == "1");

    v.clear();
    v.push_back("1");
    v.push_back("1");
    v.push_back("1");
    v = s.longestWords(v);
    assert(v.size() == 3);
    assert(v[0] == "1");
    assert(v[1] == "1");
    assert(v[2] == "1");


    v.clear();
    v.push_back("");
    v.push_back("");
    v.push_back("");
    v = s.longestWords(v);
    assert(v.size() == 3);
    assert(v[0] == "");
    assert(v[1] == "");
    assert(v[2] == "");

    return 0;
}
