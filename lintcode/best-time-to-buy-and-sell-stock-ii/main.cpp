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

        int sum = 0;
        int start = prices[0];
        for (int i = 1; i < sz; ++i) {
            if (prices[i] <= start) {
                start = prices[i];
            } else {
                sum += prices[i] - start;
                start = prices[i];
            }
        }
        return sum;
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

    int a0[] = {2,1,2,0,1};
    v = seed_array(a0, 5);
    r = s.maxProfit(v);
    assert(r == 2);

    int a1[] = {3,2,3,1,2};
    v = seed_array(a1, 5);
    r = s.maxProfit(v);
    assert(r == 2);

    int a2[] = {1, 2, 3, 4, 5};
    v = seed_array(a2, 5);
    assert(to_str(v) == "1 2 3 4 5 \n");
    r = s.maxProfit(v);
    assert(r == 4);

    int a3[] = {2,3,2,4,7,9,1};
    v = seed_array(a3, 7);
    r = s.maxProfit(v);
    assert(r == 8);

    int a4[] = {1, 1};
    v = seed_array(a4, 2);
    r = s.maxProfit(v);
    assert(r == 0);

    int a5[] = {2, 1};
    v = seed_array(a5, 2);
    r = s.maxProfit(v);
    assert(r == 0);

    int a6[] = {1,2,5};
    v = seed_array(a6, 3);
    r = s.maxProfit(v);
    assert(r == 4);

    int a7[] = {1,2,5,6};
    v = seed_array(a7, 4);
    r = s.maxProfit(v);
    assert(r == 5);

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
