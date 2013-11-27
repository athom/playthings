#include <iostream>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        int a = x;
        long b = 0;
        int i = 0;
        while(a!=0){
            b = b * 10 + a % 10;
            a = a / 10;
            i++;
        }
        return int(b);    
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.reverse(1234) << endl;
    cout << s.reverse(12304) << endl;
    cout << s.reverse(123040) << endl;
    cout << s.reverse(-1234) << endl;
    cout << s.reverse(-12304) << endl;
    cout << s.reverse(-123040) << endl;

    cout << s.reverse(1000000003) << endl;
    return 0;
}
