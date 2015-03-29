#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int i = 0;
        int j = prices.size() - 1;

        int minBuy = 999999999;
        int maxSell = -1;
        while(i<=j){
            if(prices[i] < minBuy){
                minBuy = prices[i];
            }

            if(prices[j] > maxSell){
                maxSell = prices[j];
            }

            i++;
            j--;
        }

        int maxProfit =  maxSell - minBuy;
        if (maxProfit < 0)
        {
            return 0;
        }

        return maxProfit;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    assert(s.maxProfit(v1) == 3);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(1);
    assert(s.maxProfit(v2) == 0);


    vector<int> v3;
    v3.push_back(4);
    v3.push_back(3);
    v3.push_back(2);
    v3.push_back(1);
    assert(s.maxProfit(v3) == 0);

    vector<int> v4;
    v4.push_back(2);
    v4.push_back(1);
    v4.push_back(5);
    v4.push_back(4);
    assert(s.maxProfit(v4) == 4);


    vector<int> v5;
    v5.push_back(1);
    assert(s.maxProfit(v5) == 0);

    vector<int> v6;
    assert(s.maxProfit(v6) == 0);

    vector<int> v7;
    v7.push_back(1);
    v7.push_back(4);
    v7.push_back(2);
    assert(s.maxProfit(v7) == 3);

    vector<int> v8;
    v8.push_back(3);
    v8.push_back(2);
    v8.push_back(6);
    v8.push_back(5);
    v8.push_back(0);
    v8.push_back(3);
    assert(s.maxProfit(v8) == 4);


    return 0;
}
