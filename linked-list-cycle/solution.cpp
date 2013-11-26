#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (; fast != NULL && fast->next != NULL; )
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    ListNode* t0 = new ListNode(0);
    ListNode* t1 = new ListNode(1);
    ListNode* t2 = new ListNode(2);
    ListNode* t3 = new ListNode(3);

    t0->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = NULL;

    Solution s;
    cout << s.hasCycle(t0) << endl;

    return 0;
}
