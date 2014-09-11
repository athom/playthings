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

        int a = head->val;
        ListNode* pLeft = head;
        ListNode* pRight = head;

        while(pLeft->next != NULL){
            while(pRight != NULL && pRight->val == a ){
                pRight = pRight->next;
            }
            // reach the end of the list
            if (pRight == NULL) {
                pLeft->next = NULL;
            }else{
                pLeft->next = pRight;
                pLeft = pRight;
            }
            a = pLeft->val;
        }

        return head;
    }
};


int main(int argc, char *argv[])
{

    ListNode n1(1);
    ListNode n2(1);
    ListNode n3(2);
    ListNode n4(3);
    ListNode n5(3);
    ListNode n6(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;


    for (ListNode* p = &n1; p != NULL; p = p->next)
    {
        std::cout << p->val << std::endl;
    }

    Solution s;
    s.deleteDuplicates(&n1);

    std::cout << "--------" << std::endl;

    for (ListNode* p = &n1; p != NULL; p = p->next)
    {
        std::cout << p->val << std::endl;
    }

    return 0;
}
