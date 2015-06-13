//#include<>
#include<vector>
#include<iostream>
#include<sstream>
#include <assert.h>

using namespace std;

class Solution {
public:
    /**
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        vector<int> newV;
        for (vector<int>::iterator it = A.begin(); it != A.end(); it++) {
            if (*it != elem)
            {
                newV.push_back(*it);
            }
        }
        A = newV;
        return A.size();
    }
};

string to_str(vector<int> v){
    ostringstream os;
    for(int i=0; i<v.size(); i++){
        if(i == v.size() - 1){
            os << v[i];
        }else{
            os << v[i] << " ";
        }
    }
    os << endl;
    return os.str();
}

int main(int argc, char *argv[])
{
    Solution s;
    int r;
    vector<int> v;

    v.push_back(0);
    v.push_back(4);
    v.push_back(4);
    v.push_back(0);
    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    r = s.removeElement(v, 4);
    assert(r == 4);
    assert(to_str(v) == "0 0 0 2\n");

    v.clear();
    v.push_back(0);
    v.push_back(4);
    v.push_back(4);
    v.push_back(0);
    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    r = s.removeElement(v, 7);
    assert(r == 8);
    assert(to_str(v) == "0 4 4 0 0 2 4 4\n");

    v.clear();
    v.push_back(0);
    v.push_back(4);
    v.push_back(4);
    v.push_back(0);
    v.push_back(0);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    r = s.removeElement(v, 2);
    assert(r == 7);
    assert(to_str(v) == "0 4 4 0 0 4 4\n");

    v.clear();
    r = s.removeElement(v, 2);
    assert(r == 0);
    assert(to_str(v) == "\n");

    v.clear();
    v.push_back(4);
    r = s.removeElement(v, 2);
    assert(r == 1);
    assert(to_str(v) == "4\n");

    v.clear();
    v.push_back(4);
    r = s.removeElement(v, 4);
    assert(r == 0);
    assert(to_str(v) == "\n");

    v.clear();
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    r = s.removeElement(v, 4);
    assert(r == 0);
    assert(to_str(v) == "\n");
    return 0;
}
