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
    bool anagram(string s, string t) {        // write your code here
        if (s.size() != t.size()) {
            return false;
        }

        if (s.size() == 0) {
            return true;
        }

        if (s.size() == 1) {
            return s[0] == t[0];
        }

        bool found = false;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == s[0]) {
                s.erase(0, 1);
                t.erase(i, 1);
                found = true;
                break;
            }
        }

        if (!found) {
            return false;
        }

        return anagram(s, t);
    }
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> r;
        vector<string> xorlist;
        map<string, vector<string> > xormap;
        int sz = strs.size();
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); it++) {
            bool found = false;
            string curKey;
            for (vector<string>::iterator ix = xorlist.begin(); ix != xorlist.end(); ix++) {
                if (anagram(*ix, *it)) {
                    curKey = *ix;
                    found = true;
                }
            }

            if (found) {
                xormap[curKey].push_back(*it);
            } else {
                vector<string> v;
                v.push_back(*it);
                xormap[*it] = v;
                xorlist.push_back(*it);
            }
        }

        for (map<string, vector<string> >::iterator it = xormap.begin(); it != xormap.end(); it++) {
            if ((it->second).size() <= 1) {
                continue;
            }
            for (vector<string>::iterator iv = (it->second).begin(); iv != (it->second).end(); iv++) {
                r.push_back(*iv);
            }
        }

        return r;
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
    vector<string> v;
    vector<string> ve;
    vector<string> r;

    v.clear();
    v.push_back("lint");
    v.push_back("intl");
    v.push_back("inlt");
    v.push_back("code");
    ve.clear();
    ve.push_back("lint");
    ve.push_back("intl");
    ve.push_back("inlt");
    r = s.anagrams(v);
    assert(ev(r, ve));

    v.clear();
    v.push_back("ab");
    v.push_back("ba");
    v.push_back("cd");
    v.push_back("dc");
    v.push_back("e");
    ve.clear();
    ve.push_back("ab");
    ve.push_back("ba");
    ve.push_back("cd");
    ve.push_back("dc");
    r = s.anagrams(v);
    assert(ev(r, ve));

    v.clear();
    v.push_back("ab");
    v.push_back("bc");
    v.push_back("cd");
    ve.clear();
    r = s.anagrams(v);
    assert(ev(r, ve));

    v.clear();
    v.push_back("");
    v.push_back("");
    v.push_back("ab");
    v.push_back("bc");
    v.push_back("cd");
    ve.clear();
    ve.push_back("");
    ve.push_back("");
    r = s.anagrams(v);
    assert(ev(r, ve));

    v.clear();
    v.push_back("apt");
    v.push_back("man");
    v.push_back("qom");
    v.push_back("apt");
    v.push_back("lei");
    v.push_back("hus");
    v.push_back("pet");
    v.push_back("gay");
    v.push_back("six");
    v.push_back("mai");
    ve.clear();
    ve.push_back("apt");
    ve.push_back("apt");
    r = s.anagrams(v);
    //cout << to_str(v);
    //cout << to_str(r);
    //cout << to_str(ve);
    assert(ev(r, ve));

    v.clear();
    ve.clear();
    r = s.anagrams(v);
    assert(ev(r, ve));
    return 0;
}
