//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include <assert.h>
#include <utility>

using namespace std;

/**
 * Definition of ListNode
 */
class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
};

class MinStack {
private:
    vector<int> v;
    vector<int> mv;
    int top;
    int mtop;
public:
    MinStack() {
        v.clear();
        mv.clear();
        top = -1;
        mtop = -1;
    }

    void push(int number) {
        v.push_back(number);
        top++;
        if (mtop == -1) {
            mv.push_back(number);
            mtop++;
        } else if (number <= mv[mtop]) {
            mv.push_back(number);
            mtop++;
        }
    }

    int pop() {
        if (top == -1) {
            return -1;
        }
        int r = v[top];
        v.erase(v.begin() + top);
        top--;
        if (r <= mv[mtop]) {
            mv.erase(mv.begin() + mtop);
            mtop--;
        }

        return r;
    }

    int min() {
        return mv[mtop];
    }
};

string to_str(ListNode* p){
    ostringstream os;
    while(p){
        os << p->val << " ";
        p = p->next;
    }
    os << "NULL" << endl;
    return os.str();
}

ListNode* seed_list(const int* a, int len) {
    ListNode* head = NULL;
    ListNode* last = NULL;

    for (int i = 0; i < len; i++)
    {
        ListNode* n = new ListNode(a[i]);
        if (i == 0)
        {
            head = n;
            last = n;
        }else{
            last->next = n;
            last = n;
        }
    }

    return head;
}

int main(int argc, char *argv[])
{
    MinStack ms;
    int r;

    ms.push(1);
    r = ms.pop();
    assert(r == 1);
    ms.push(2);
    ms.push(3);
    r = ms.min();
    assert(r == 2);
    ms.push(1);
    r = ms.min();
    assert(r == 1);



    return 0;
}
