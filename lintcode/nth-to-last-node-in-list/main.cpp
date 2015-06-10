//#include<>
#include<string>
#include<iostream>
#include<queue>
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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */

    // Big array verion, ocupied too much space
    //ListNode *nthToLast(ListNode *head, int n) {
        //// write your code here
        //ListNode* array[999999];

        //ListNode* cur = head;
        //array[0] = cur;
        //int index = 0;
        //while (cur) {
            //cur = cur->next;
            //index++;
            //array[index] = cur;
        //}
        //return array[index-n];
    //}

    ListNode *nthToLast(ListNode *head, int n) {
        queue<ListNode*> q;
        ListNode* cur = head;
        while (cur) {
            q.push(cur);
            if (q.size() > n)
            {
                q.pop();
            }
            cur = cur->next;
        }
        q.push(cur);
        return q.front();
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
    p = s.nthToLast(&n1, 2);
    assert(p->val == 4);

    p = s.nthToLast(&n1, 1);
    assert(p->val == 5);


    ListNode n0(1);
    p = s.nthToLast(&n0, 0);
    assert(p == NULL);
    p = s.nthToLast(&n0, 1);
    assert(p->val == (1));

    p = s.nthToLast(NULL, 0);
    assert(p == NULL);

    return 0;
}
