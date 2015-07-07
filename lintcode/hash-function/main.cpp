//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <cmath>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        int sz = key.size();
        if (sz == 0) {
            return 0;
        }

        unsigned long long sum = 0;
        //int sum = 0;
        for (int i = 0; i < sz; ++i) {
            //sum += ((unsigned long long)(key[i]) * (unsigned long long)(pow(33, sz-1-i)))/HASH_SIZE;
            sum = (sum * 33) + (unsigned long long)(key[i]);
            sum %= HASH_SIZE;
        }

        return sum;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    int r;

    r = s.hashCode("abcdefghijklmnopqrstuvwxyz", 2607);
    assert(r == 1673);

    r = s.hashCode("abcd", 100);
    assert(r == 78);

    r = s.hashCode("abcd", 1000);
    assert(r == 978);


    r = s.hashCode("", 100);
    assert(r == 0);
    return 0;
}
