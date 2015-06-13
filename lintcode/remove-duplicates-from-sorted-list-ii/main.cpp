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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* pre = NULL;
        ListNode* cur = head;

        while (cur) {
            bool sweep = false;
            while (cur->next && cur->next->val == cur->val) {
                    ListNode* old = cur;
                    cur = cur->next;
                    delete old;
                    sweep = true;
            }
            if (cur->next == NULL) {
                if (sweep) {
                    if (pre == NULL) {
                        return NULL;
                    }

                    pre->next = NULL;
                    delete cur;
                }
                return head;
            }

            if (sweep) {
                if (pre == NULL) {
                    head = cur->next;
                } else {
                    pre->next = cur->next;
                }

                ListNode* old = cur;
                cur = cur->next;
                delete old;
                continue;
            }

            pre = cur;
            cur = cur->next;
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
    ListNode* p1;

    int a[] = {1, 2, 3, 3, 4, 4, 5};
    p1 = seed_list(a, 7);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "1 2 5 NULL\n");

    int a1[] = {1, 1, 1, 2, 3};
    p1 = seed_list(a1, 5);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "2 3 NULL\n");

    int bbb1[] = {1, 1, 2};
    p1 = seed_list(bbb1, 3);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "2 NULL\n");

    int bb1[] = {1, 1, 2, 3, 3};
    p1 = seed_list(bb1, 5);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "2 NULL\n");

    int b1[] = {1, 1, 1};
    p1 = seed_list(b1, 3);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "NULL\n");

    int b2[] = {1};
    p1 = seed_list(b2, 1);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "1 NULL\n");

    int b3[] = {1, 1, 1, 2, 2, 2};
    p1 = seed_list(b3, 6);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "NULL\n");

    p = s.deleteDuplicates(NULL);
    assert(to_str(p) == "NULL\n");
    return 0;
}
