//#include<>
#include<iostream>
#include<sstream>
#include<map>
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
    ListNode* findMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = NULL;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return pre;
        //return slow;
    }

    ListNode* mergeTwoSortedList(ListNode* p1, ListNode* p2) {
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
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return mergeTwoSortedList(left, right);
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

    for (int i = 0; i < len; i++) {
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
    ListNode* pm;

    int a1[] = {1, 4, 3, 2, 5, 2};
    p = seed_list(a1, 6);
    assert(to_str(p) == "1 4 3 2 5 2 NULL\n");
    pm = s.findMiddle(p);
    //assert(pm->val == 2);
    assert(pm->val == 3);
    p = s.sortList(p);
    assert(to_str(p) == "1 2 2 3 4 5 NULL\n");

    int a2[] = {1};
    p = seed_list(a2, 1);
    assert(to_str(p) == "1 NULL\n");
    pm = s.findMiddle(p);
    //assert(pm->val == 1);
    assert(pm == NULL);
    p = s.sortList(p);
    assert(to_str(p) == "1 NULL\n");

    int a3[] = {1, 2, 3};
    p = seed_list(a3, 3);
    assert(to_str(p) == "1 2 3 NULL\n");
    pm = s.findMiddle(p);
    //assert(pm->val == 2);
    assert(pm->val == 1);
    p = s.sortList(p);
    assert(to_str(p) == "1 2 3 NULL\n");

    int a4[] = {3, 2, 1};
    p = seed_list(a4, 3);
    assert(to_str(p) == "3 2 1 NULL\n");
    pm = s.findMiddle(p);
    //assert(pm->val == 2);
    assert(pm->val == 3);
    p = s.sortList(p);
    assert(to_str(p) == "1 2 3 NULL\n");

    pm = s.findMiddle(NULL);
    assert(pm == NULL);
    p = s.sortList(NULL);
    assert(to_str(p) == "NULL\n");
    return 0;
}
