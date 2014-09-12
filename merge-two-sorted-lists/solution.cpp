#include <iostream>
#include <vector>
using namespace std;

// 1, 2, 2, 4
// 1, 2, 3, 4, 7

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }

        ListNode* other = NULL;
        ListNode* p = NULL;

        ListNode* p1= l1;
        ListNode* p2= l2;


        while (p1 != NULL && p2 != NULL){
            if(p1->val <= p2->val)
            {
                if (p == NULL)
                {
                    p = p1;
                    other = p;
                    p1 = p1->next;
                    p->next = NULL;
                }else{
                    p->next = p1;
                    p1 = p1->next;
                    p = p->next;
                }
            }else{
                if (p == NULL)
                {
                    p = p2;
                    other = p;
                    p2 = p2->next;
                    p->next = NULL;
                }else{
                    p->next = p2;
                    p2 = p2->next;
                    p = p->next;
                }
            }
        }

        if (p1 != NULL)
        {
            p->next = p1;
        }
        if (p2 != NULL)
        {
            p->next = p2;
        }

        return other;
    }
};

int main(int argc, char *argv[])
{

    ListNode n1(2);
    ListNode n2(2);
    ListNode n3(2);
    ListNode n4(3);
    ListNode n5(4);
    ListNode n6(4);
    ListNode n7(4);
    ListNode n8(7);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;

    ListNode m1(1);
    ListNode m2(4);
    ListNode m3(5);
    ListNode m4(6);
    ListNode m5(7);
    m1.next = &m2;
    m2.next = &m3;
    m3.next = &m4;
    m4.next = &m5;


    for (ListNode* p = &n1; p != NULL; p = p->next)
    {
        std::cout << p->val << std::endl;
    }

    std::cout << "--------" << std::endl;

    for (ListNode* p = &m1; p != NULL; p = p->next)
    {
        std::cout << p->val << std::endl;
    }

    Solution s;
    ListNode* z = s.mergeTwoLists(&n1, &m1);

    std::cout << "=========" << std::endl;

    for (ListNode* p = z; p != NULL; p = p->next)
    {
        std::cout << p->val << std::endl;
    }

    return 0;
}
