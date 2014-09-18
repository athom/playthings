#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
        {
           return NULL;
        }

        ListNode* pHead = NULL;
        ListNode* pTail = NULL;
        ListNode* pRight = head;

        while(pRight != NULL){
            bool hasRepeat = false;
            while(pRight->next != NULL && pRight->val == pRight->next->val ){
                pRight = pRight->next;
                hasRepeat = true;
            }


            if (!hasRepeat){
                if (pHead == NULL)
                {
                    pHead = pRight;
                    pTail = pRight;
                }else{
                    pTail->next = pRight;
                    pTail = pRight;
                }
            }

            pRight = pRight->next;
            if (pTail != NULL)
            {
                pTail->next = NULL;
            }
        }

        return pHead;
    }
};


int main(int argc, char *argv[])
{

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(3);
    ListNode n5(4);
    ListNode n6(4);
    ListNode n7(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;


    for (ListNode* p = &n1; p != NULL; p = p->next)
    {
        std::cout << p->val << std::endl;
    }

    Solution s;
    ListNode* h = s.deleteDuplicates(&n1);

    std::cout << "--------" << std::endl;

    for (ListNode* p = h; p != NULL; p = p->next)
    {
        std::cout << p->val << std::endl;
    }

    return 0;
}
