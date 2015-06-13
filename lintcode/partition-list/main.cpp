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
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if (head == NULL) {
            return NULL;
        }

        ListNode* pre = NULL;
        ListNode* cur = head;

        ListNode* marker_pre = NULL;
        ListNode* marker_cur = NULL;

        while (cur) {
            // meet the patrition maker
            if (marker_cur == NULL && cur->val >= x) {
                marker_pre = pre;
                marker_cur = cur;
                pre = cur;
                cur = cur->next;
                continue;
            }

            // skippable
            if (marker_cur == NULL || cur->val >= x) {
                pre = cur;
                cur = cur->next;
                continue;
            }

            // move current node before the marker
            ListNode* next = cur->next;
            pre->next = next;
            cur->next = marker_cur;
            if (marker_pre) {
                marker_pre->next = cur;
            }else{
                head = cur;
            }
            marker_pre = cur;
            cur = next;
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

    int a1[] = {1, 4, 3, 2, 5, 2};
    p = seed_list(a1, 6);
    assert(to_str(p) == "1 4 3 2 5 2 NULL\n");
    p = s.partition(p, 3);
    assert(to_str(p) == "1 2 2 4 3 5 NULL\n");

    int a2[] = {1};
    p = seed_list(a2, 1);
    assert(to_str(p) == "1 NULL\n");
    p = s.partition(p, 1);
    assert(to_str(p) == "1 NULL\n");

    int a3[] = {1, 1, 1, 1};
    p = seed_list(a3, 4);
    assert(to_str(p) == "1 1 1 1 NULL\n");
    p = s.partition(p, 1);
    assert(to_str(p) == "1 1 1 1 NULL\n");

    int a4[] = {3, 2, 1, 1};
    p = seed_list(a4, 4);
    assert(to_str(p) == "3 2 1 1 NULL\n");
    p = s.partition(p, 1);
    assert(to_str(p) == "3 2 1 1 NULL\n");

    int a5[] = {3, 2, 1, 1};
    p = seed_list(a5, 4);
    assert(to_str(p) == "3 2 1 1 NULL\n");
    p = s.partition(p, 2);
    assert(to_str(p) == "1 1 3 2 NULL\n");

    p = s.partition(NULL, 1);
    assert(to_str(p) == "NULL\n");

    return 0;
}
