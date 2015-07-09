//#include<>
#include<string>
#include<iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        int len = length;
        for (int i = 0; i < len; ++i) {
            if (string[i] == ' ') {
                string[i] = '%';
                len += 2;
                for (int j = len-1; j >= i+3; --j) {
                    string[j] = string[j-2];
                }
                string[i+1] = '2';
                string[i+2] = '0';
                i+=2;
            }
        }

        return 0;
    }
};



int main(int argc, char *argv[])
{
    Solution s;
    int r;
    char str[50] = "hello world";
    r = s.replaceBlank(str, 11);
    assert(strcmp(str,"hello%20world") == 0);

    char str2[50] = "Mr John Smith";
    r = s.replaceBlank(str2, 13);
    assert(strcmp(str2,"Mr%20John%20Smith") == 0);
    return 0;
}
