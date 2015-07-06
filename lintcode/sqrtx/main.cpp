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
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if (x <= 1) {
            return x;
        }

        unsigned long long low = 0;
        unsigned long long high = x;
        unsigned long long a = x/2;
        unsigned long long target = x;
        unsigned long long r = 0;
        unsigned long long s = 0;
        while (true) {
            r = a*a;
            s = (a+1)*(a+1);
            if (r == target) {
                return a;
            }
            if ((r < target) && s > target) {
                return a;
            }


            if (r < target) {
                low = a;
                a = (high + low)/2;
            } else {
                high = a;
                a = (high + low)/2;
            }
        }

        return -1;
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
    int r;

    r = s.sqrt(999999999);
    assert(r == 31622);

    r = s.sqrt(99999999);
    assert(r == 9999);

    r = s.sqrt(0);
    assert(r == 0);

    r = s.sqrt(1);
    assert(r == 1);

    r = s.sqrt(2);
    assert(r == 1);

    r = s.sqrt(3);
    assert(r == 1);

    r = s.sqrt(4);
    assert(r == 2);

    r = s.sqrt(5);
    assert(r == 2);

    r = s.sqrt(10);
    assert(r == 3);

    r = s.sqrt(101);
    assert(r == 10);

    r = s.sqrt(10001);
    assert(r == 100);

    r = s.sqrt(99);
    assert(r == 9);

    r = s.sqrt(122);
    assert(r == 11);


    r = s.sqrt(100000001);
    assert(r == 10000);

    return 0;
}
