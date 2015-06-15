//#include<>
#include<iostream>
#include<sstream>
#include<stack>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (stk.empty()) {
                    return false;
                }
                if (stk.top() != '(') {
                    return false;
                }

                stk.pop();
                continue;
            }
            if (s[i] == ']') {
                if (stk.empty()) {
                    return false;
                }
                if (stk.top() != '[') {
                    return false;
                }

                stk.pop();
                continue;
            }
            if (s[i] == '}') {
                if (stk.empty()) {
                    return false;
                }
                if (stk.top() != '{') {
                    return false;
                }

                stk.pop();
                continue;
            }

            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            }
        }

        return stk.empty();
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    string ss;
    ss = "()";
    assert(s.isValidParentheses(ss) == true);
    ss = "[]";
    assert(s.isValidParentheses(ss) == true);
    ss = "{}";
    assert(s.isValidParentheses(ss) == true);
    ss = "([])";
    assert(s.isValidParentheses(ss) == true);
    ss = "({})";
    assert(s.isValidParentheses(ss) == true);
    ss = "[()]";
    assert(s.isValidParentheses(ss) == true);
    ss = "[{}]";
    assert(s.isValidParentheses(ss) == true);
    ss = "{()}";
    assert(s.isValidParentheses(ss) == true);
    ss = "{[]}";
    assert(s.isValidParentheses(ss) == true);
    ss = "()[]{}";
    assert(s.isValidParentheses(ss) == true);
    ss = "";
    assert(s.isValidParentheses(ss) == true);

    ss = "(";
    assert(s.isValidParentheses(ss) == false);
    ss = "[";
    assert(s.isValidParentheses(ss) == false);
    ss = "{";
    assert(s.isValidParentheses(ss) == false);
    ss = ")";
    assert(s.isValidParentheses(ss) == false);
    ss = "]";
    assert(s.isValidParentheses(ss) == false);
    ss = "}";
    assert(s.isValidParentheses(ss) == false);
    ss = "(]";
    assert(s.isValidParentheses(ss) == false);
    ss = "([)]";
    assert(s.isValidParentheses(ss) == false);
    return 0;
}
