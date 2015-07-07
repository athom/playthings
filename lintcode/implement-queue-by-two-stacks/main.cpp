//#include<>
#include <iostream>
#include <sstream>
#include <stack>
#include <assert.h>
#include <utility>

using namespace std;

/**
 * Definition of ListNode
 */

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        int r;
        while (!stack1.empty()) {
            r = stack1.top();
            stack1.pop();
            stack2.push(r);
        }
        stack1.push(element);
        while (!stack2.empty()) {
            r = stack2.top();
            stack2.pop();
            stack1.push(r);
        }
    }

    int pop() {
        int r = stack1.top();
        stack1.pop();
        return r;
    }

    int top() {
        return stack1.top();
    }
};



int main(int argc, char *argv[])
{
    Queue q;
    int r;

    q.push(1);
    r = q.pop();
    assert(r == 1);
    q.push(2);
    q.push(3);
    r = q.top();
    assert(r == 2);
    r = q.pop();
    assert(r == 2);
    r = q.pop();
    assert(r == 3);

    return 0;
}
