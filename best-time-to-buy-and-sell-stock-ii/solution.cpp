#include <iostream>
#include <vector>
using namespace std;


struct P {
    int price;
    bool bought;
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        std::vector<P> ps;
        for (vector<int>::iterator it = prices.begin(); it < prices.end(); it++)
        {
            P p;
            p.price = *it;
            p.bought = false;
            ps.push_back(p);
        }

        int sum = 0;
        for (vector<P>::iterator it = ps.begin(); it < ps.end(); it++)
        {
            if (it->bought)
            {
                continue;
            }
            it->bought = true;

            int min_price = it->price;
            vector<P>::iterator min_jt = it;
            for (vector<P>::iterator jt = it+1; jt < ps.end(); jt++)
            {
                if (jt->bought || jt->price > it->price)
                {
                    continue;
                }
                if (jt->price < min_price)
                {
                    min_price = jt->price;
                    min_jt = jt;
                }
            }

            if(min_jt != it)
            {
                min_jt->bought = true;
            }

            sum += it->price - min_price;
            
        }
        return sum;    
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> v;
    //v.push_back(5);
    //v.push_back(3);
    //v.push_back(2);
    //v.push_back(3);
    //v.push_back(1);
    //v.push_back(3);
    //v.push_back(2);
    //v.push_back(3);

    //v.push_back(1);
    //v.push_back(2);
    //v.push_back(3);
    //v.push_back(4);
    //v.push_back(5);
    //v.push_back(6);
    //v.push_back(7);
    //v.push_back(8);

    v.push_back(8);
    v.push_back(9);
    v.push_back(6);
    v.push_back(5);
    v.push_back(9);
    v.push_back(3);
    v.push_back(6);
    v.push_back(1);

    Solution s;
    cout << s.maxProfit(v) << endl;
    return 0;
}
