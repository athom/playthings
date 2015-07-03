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
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = NULL;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return pre;
    }

    ListNode *reverse(ListNode *head) {
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
    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        ListNode* head = NULL;
        ListNode* cur = head;
        while (p1 && p2) {
            if (head == NULL) {
                head = p1;
                cur = head;
                p1 = p1->next;
                cur->next = p2;
                cur = cur->next;
                p2 = p2->next;
                continue;
            }

            cur->next = p1;
            cur = cur->next;
            p1 = p1->next;
            cur->next = p2;
            cur = cur->next;
            p2 = p2->next;
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
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;
        right = reverse(right);
        head = mergeTwoLists(left, right);
        return;
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
    Solution s;
    ListNode* p;


    int a1[] = {1, 2, 3, 4};
    p = seed_list(a1, 4);
    s.reorderList(p);
    assert(to_str(p) == "1 4 2 3 NULL\n");

    int a2[] = {1, 2, 3, 4, 5};
    p = seed_list(a2, 5);
    s.reorderList(p);
    assert(to_str(p) == "1 5 2 4 3 NULL\n");

    int a3[] = {1, 2};
    p = seed_list(a3, 2);
    s.reorderList(p);
    assert(to_str(p) == "1 2 NULL\n");

    int a4[] = {1, 2, 3};
    p = seed_list(a4, 3);
    s.reorderList(p);
    assert(to_str(p) == "1 3 2 NULL\n");

    int a5[] = {1};
    p = seed_list(a5, 1);
    s.reorderList(p);
    assert(to_str(p) == "1 NULL\n");

    p = NULL;
    s.reorderList(p);
    assert(to_str(p) == "NULL\n");
    return 0;
}
