//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

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

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int sz = prices.size();
        if (sz == 0 || sz == 1) {
            return 0;
        }

        vector<int> M;
        for (int i = 0; i < sz; ++i) {
            M.push_back(prices[i]);
        }

        int maxValue = 0;
        for (int i = 1; i < sz; ++i) {
            if (M[i] >= M[i-1]) {
                maxValue = max(maxValue, M[i]-M[i-1]);
                M[i] = M[i-1];
            }
        }
        return maxValue;
    }
};


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
    int r;

    int a1[] = {3,2,3,1,2};
    v = seed_array(a1, 5);
    r = s.maxProfit(v);
    assert(r == 1);

    int a2[] = {1, 2, 3, 4, 5};
    v = seed_array(a2, 5);
    assert(to_str(v) == "1 2 3 4 5 \n");
    r = s.maxProfit(v);
    assert(r == 4);

    int a3[] = {2,3,2,4,7,9,1};
    v = seed_array(a3, 7);
    r = s.maxProfit(v);
    assert(r == 7);

    int a4[] = {1, 1};
    v = seed_array(a4, 2);
    r = s.maxProfit(v);
    assert(r == 0);

    int a5[] = {2, 1};
    v = seed_array(a5, 2);
    r = s.maxProfit(v);
    assert(r == 0);


    int a8[] = {1};
    v = seed_array(a8, 1);
    assert(to_str(v) == "1 \n");
    r = s.maxProfit(v);
    assert(r == 0);


    v.clear();
    r = s.maxProfit(v);
    assert(r == 0);
    return 0;
}
