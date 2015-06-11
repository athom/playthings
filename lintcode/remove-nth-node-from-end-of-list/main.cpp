//#include<>
#include<iostream>
#include<queue>
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

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        queue<pair <ListNode*,ListNode*> > q;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur) {
            pair<ListNode*, ListNode*> p;
            p = make_pair(pre, cur);
            q.push(p);
            if (q.size() > n)
            {
                q.pop();
            }
            pre = cur;
            cur = cur->next;
        }

        pair<ListNode*, ListNode*> p;
        p = make_pair(pre, cur);
        q.push(p);

        pair<ListNode*, ListNode*> first_pair = q.front();
        if (first_pair.first == NULL && first_pair.second) {
            return first_pair.second->next;
        }

        if (first_pair.first && first_pair.second)
        {
            first_pair.first->next = first_pair.second->next;
        }

        return head;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    ListNode* p;

    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;
    p = s.removeNthFromEnd(&n1, 2);
    for (int i = 0; i < 3; ++i)
    {
        assert(p->val == (i+1));
        p = p->next;
    }
    assert(p->val == 5);


    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;
    p = s.removeNthFromEnd(&n1, 0);
    for (int i = 0; i < 4; ++i)
    {
        assert(p->val == (i+1));
        p = p->next;
    }
    assert(p->val == 5);


    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;
    p = s.removeNthFromEnd(&n1, 5);
    for (int i = 0; i < 4; ++i)
    {
        assert(p->val == (i+2));
        p = p->next;
    }
    //assert(p->val == 5);

    p = s.removeNthFromEnd(&n5, 0);
    assert(p == &n5);

    p = s.removeNthFromEnd(&n5, 1);
    assert(p == NULL);

    p = s.removeNthFromEnd(NULL, 0);
    assert(p == NULL);
    return 0;
}
