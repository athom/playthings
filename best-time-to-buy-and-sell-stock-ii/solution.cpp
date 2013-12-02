#include <iostream>
#include <vector>
using namespace std;


const int INVALID_NUM = -1;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int sum = 0;
        for (vector<int>::iterator it = prices.begin(); it < prices.end(); it++)
        {
            if (*it == INVALID_NUM)
            {
                continue;
            }

            int min_price = *it;
            vector<int>::iterator min_jt = it;
            for (vector<int>::iterator jt = it+1; jt < prices.end(); jt++)
            {
                if (*jt == INVALID_NUM || *jt > *it)
                {
                    continue;
                }

                if (*jt < min_price)
                {
                    min_price = *jt;
                    min_jt = jt;
                }
            }

            sum += (*it - *min_jt); 
            *min_jt = INVALID_NUM;
        }
        return sum;    
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(3);

    //v.push_back(1);
    //v.push_back(2);
    //v.push_back(3);
    //v.push_back(4);
    //v.push_back(5);
    //v.push_back(6);
    //v.push_back(7);
    //v.push_back(8);

    //v.push_back(8);
    //v.push_back(9);
    //v.push_back(6);
    //v.push_back(5);
    //v.push_back(9);
    //v.push_back(3);
    //v.push_back(6);
    //v.push_back(1);

    Solution s;
    cout << s.maxProfit(v) << endl;
    return 0;
}
