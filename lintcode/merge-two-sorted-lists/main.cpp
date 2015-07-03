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

class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *p1, ListNode *p2) {
        if (p1 == NULL) {
            return p2;
        }
        if (p2 == NULL) {
            return p1;
        }
        ListNode* head = NULL;
        ListNode* cur = head;
        while (p1 && p2) {
            if (head == NULL) {
                if (p1->val < p2->val) {
                    head = p1;
                    p1 = p1->next;
                } else {
                    head = p2;
                    p2 = p2->next;
                }
                cur = head;
                continue;
            }

            if (p1->val < p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }

        if (p1) {
            cur->next = p1;
        }
        if (p2) {
            cur->next = p2;
        }
        return head;

    }
    //ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        //// write your code here
        //if (l2 == NULL) {
            //return l1;
        //}
        //if (l1 == NULL) {
            //return l2;
        //}
        //ListNode* head1 = l1;
        //ListNode* cur1 = l1;
        //ListNode* cur2 = l2;
        //ListNode* pre1 = NULL;
        //while(cur1) {
            //if (cur2 == NULL) {
                //break;
            //}
            //while (cur2 && (cur1->val > cur2->val)) {
                //// insert before list1's first node
                //if (pre1 == NULL) {
                    //ListNode* cur2_next = cur2->next;
                    //cur2->next = cur1;
                    //head1 = cur2;
                    //pre1 = cur2;
                    //cur2 = cur2_next;
                //} else {
                    //ListNode* cur2_next = cur2->next;
                    //cur2->next = cur1;
                    //pre1->next = cur2;
                    //pre1 = cur2;
                    //cur2 = cur2_next;
                //}
            //}
            //pre1 = cur1;
            //cur1 = cur1->next;
        //}

        //if (cur2) {
            //pre1->next = cur2;
        //}
        //return head1;
    //}
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
    Solution s;
    ListNode* p;
    ListNode* p1;
    ListNode* p2;

    int bbb1[] = {6, 8, 8, 10};
    p1 = seed_list(bbb1, 4);
    int bbb2[] = {1, 2, 3, 7};
    p2 = seed_list(bbb2, 4);
    p = s.mergeTwoLists(p1, p2);
    assert(to_str(p) == "1 2 3 6 7 8 8 10 NULL\n");

    int bb1[] = {6, 8, 8, 10, 16, 16, 19};
    p1 = seed_list(bb1, 7);
    int bb2[] = {2, 2, 13, 16};
    p2 = seed_list(bb2, 4);
    p = s.mergeTwoLists(p1, p2);
    assert(to_str(p) == "2 2 6 8 8 10 13 16 16 16 19 NULL\n");


    int b1[] = {1,3,5,7,9};
    p1 = seed_list(b1, 5);
    int b2[] = {0,2,4,6,8};
    p2 = seed_list(b2, 5);
    p = s.mergeTwoLists(p1, p2);
    assert(to_str(p) == "0 1 2 3 4 5 6 7 8 9 NULL\n");


    int aa1[] = {1, 3};
    p1 = seed_list(aa1, 2);
    int aa2[] = {2,4};
    p2 = seed_list(aa2, 2);
    p = s.mergeTwoLists(p1, p2);
    assert(to_str(p) == "1 2 3 4 NULL\n");

    int aaa1[] = {1};
    p1 = seed_list(aaa1, 1);
    int aaa2[] = {2};
    p2 = seed_list(aaa2, 1);
    p = s.mergeTwoLists(p1, p2);
    assert(to_str(p) == "1 2 NULL\n");

    int aaaa1[] = {2};
    p1 = seed_list(aaaa1, 1);
    int aaaa2[] = {1};
    p2 = seed_list(aaaa2, 1);
    p = s.mergeTwoLists(p1, p2);
    assert(to_str(p) == "1 2 NULL\n");

    int aaaaa1[] = {2};
    p1 = seed_list(aaaaa1, 1);
    int aaaaa2[] = {1, 3, 8, 11, 15};
    p2 = seed_list(aaaaa2, 5);
    p = s.mergeTwoLists(p1, p2);
    assert(to_str(p) == "1 2 3 8 11 15 NULL\n");

    p = s.mergeTwoLists(NULL, NULL);
    assert(to_str(p) == "NULL\n");

    p2 = seed_list(aaaaa2, 5);
    p = s.mergeTwoLists(NULL, p2);
    assert(to_str(p) == "1 3 8 11 15 NULL\n");

    p2 = seed_list(aaaaa2, 5);
    p = s.mergeTwoLists(p2, NULL);
    assert(to_str(p) == "1 3 8 11 15 NULL\n");
    return 0;
}
