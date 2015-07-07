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
    bool isNonWordCharacter(char c){
        return c == ' ' || c == '\t' || c == '\n';
    }
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        int sz = s.size();
        if (sz == 0) {
            return "";
        }

        vector<string> v;
        string word;
        for (int i = 0; i < sz; ++i) {
            if (isNonWordCharacter(s[i])) {
                if(word.size() > 0){
                    v.push_back(word);
                    word.clear();
                }
                continue;
            }
            word.push_back(s[i]);
        }
        if(word.size() > 0){
            v.push_back(word);
        }

        string ss;
        int wordSize = v.size();
        for (int i = wordSize-1; i >= 0; --i) {
            if (i == wordSize-1) {
                ss.append(v[i]);
                continue;
            }
            ss.append(" " + v[i]);
        }

        return ss;
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
    string r;

    r = s.reverseWords("the sky is blue");
    assert(r == "blue is sky the");

    r = s.reverseWords("the sky is blue ");
    assert(r == "blue is sky the");

    r = s.reverseWords(" the sky is blue");
    assert(r == "blue is sky the");

    r = s.reverseWords(" the sky is blue ");
    assert(r == "blue is sky the");

    r = s.reverseWords(" the sky is\tblue ");
    assert(r == "blue is sky the");

    r = s.reverseWords(" the sky is \tblue ");
    assert(r == "blue is sky the");

    r = s.reverseWords(" ");
    assert(r == "");

    r = s.reverseWords("  ");
    assert(r == "");

    r = s.reverseWords("\t");
    assert(r == "");

    r = s.reverseWords("\t ");
    assert(r == "");
    return 0;
}
