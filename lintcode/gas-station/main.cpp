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
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int szG = gas.size();
        int szC = cost.size();
        if (szG == 0 || szG != szC) {
            return -1;
        }
        int sz = szG;

        int acc = 0;
        int go = 0;
        int min = ~(1<<31);
        int index = -1;
        for (int i = 0; i < sz; ++i) {
            int r = gas[i] - cost[i];
            go += r;
            acc += r;
            if (go < 0) {
                go = 0;
                index = i;
            }
        }

        if (acc < 0) {
            return -1;
        }

        if (index + 1 >= sz) {
            return 0;
        }
        return index + 1;
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
    vector<int> v;
    vector<int> v1;
    vector<int> v2;
    int r;

    v1.clear();
    v2.clear();
    r = s.canCompleteCircuit(v1, v2);
    assert(r == -1);

    int a1[] = {1, 1, 3, 1};
    int b1[] = {2, 2, 1, 1};
    v1 = seed_array(a1, 4);
    v2 = seed_array(b1, 4);
    r = s.canCompleteCircuit(v1, v2);
    assert(r == 2);

    int a2[] = {1, 5, 7};
    int b2[] = {4, 5, 6};
    v1 = seed_array(a2, 3);
    v2 = seed_array(b2, 3);
    r = s.canCompleteCircuit(v1, v2);
    assert(r == -1);

    int a3[] = {2,0,1,2,3,4,0};
    int b3[] = {0,1,0,0,0,0,11};
    v1 = seed_array(a3, 7);
    v2 = seed_array(b3, 7);
    r = s.canCompleteCircuit(v1, v2);
    assert(r == 0);

    int a4[] = {31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    int b4[] = {36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
    v1 = seed_array(a4, 50);
    v2 = seed_array(b4, 50);
    r = s.canCompleteCircuit(v1, v2);
    assert(r == 15);
    return 0;
}
