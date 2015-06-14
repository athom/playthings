//#include<>
#include<string>
#include<iostream>
#include<sstream>
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        if (m == n) {
            return head;
        }

        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* start = NULL;
        ListNode* startPre = NULL;
        ListNode* last = NULL;
        ListNode* lastNext = NULL;

        int count = 1;
        while (cur) {
            if (count == m) {
                startPre = pre;
                start = cur;
            }
            if (count == n) {
                last = cur;
                lastNext = cur->next;
            }

            pre = cur;
            cur = cur->next;
            count++;
        }

        pre = startPre;
        cur = start;
        while(cur != lastNext){
            ListNode* curOldNext = cur->next;
            if (pre == startPre) {
                cur->next = lastNext;
            } else {
                cur->next = pre;
            }
            pre = cur;
            cur = curOldNext;
        }

        if (startPre == NULL) {
            head = last;
        } else {
            startPre->next = last;
        }
        return head;
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

    int b1[] = {1, 2, 3, 4, 5};
    p = seed_list(b1, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.reverseBetween(p, 2, 4);
    assert(to_str(p) == "1 4 3 2 5 NULL\n");

    int b2[] = {1, 2, 3, 4, 5};
    p = seed_list(b2, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.reverseBetween(p, 1, 1);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");

    int b3[] = {1, 2, 3, 4, 5};
    p = seed_list(b3, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.reverseBetween(p, 5, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");

    int b4[] = {1, 2, 3, 4, 5};
    p = seed_list(b4, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.reverseBetween(p, 1, 5);
    assert(to_str(p) == "5 4 3 2 1 NULL\n");

    int b5[] = {1};
    p = seed_list(b5, 1);
    assert(to_str(p) == "1 NULL\n");
    p = s.reverseBetween(p, 1, 1);
    assert(to_str(p) == "1 NULL\n");

    p = s.reverseBetween(NULL, 0, 0);
    assert(to_str(p) == "NULL\n");
    return 0;
}
