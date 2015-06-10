//#include<>
#include<string>
#include<iostream>
#include <assert.h>

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

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode* pre = NULL;
        ListNode* cur = head;

        while(cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};



int main(int argc, char *argv[])
{
    Solution s;
    ListNode* p;

    ListNode n1(1), n2(2), n3(3), n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;
    p = s.reverse(&n1);
    for (int i = 0; i < 4; ++i)
    {
        assert(p->val == (4-i));
        p = p->next;
    }


    ListNode n0(1);
    p = s.reverse(&n0);
    for (int i = 0; i < 1; ++i)
    {
        assert(p->val == (1-i));
        p = p->next;
    }

    p = s.reverse(NULL);
    assert(p == NULL);

    return 0;
}
