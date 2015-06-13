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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if (head == NULL) {
            return false;
        }

        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p1 && p2 && p1 != p2) {
            if (p2->next == NULL || p2->next->next == NULL) {
                return false;
            }

            p2 = p2->next->next;
            p1 = p1->next;
        }

        return (p1 != NULL) && (p2 != NULL);
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
    ListNode* pd;
    //ListNode* last;

    int a1[] = {1, 4, 3, 2, 5, 2};
    p = seed_list(a1, 6);
    p->next->next->next->next->next = p->next->next;
    assert(s.hasCycle(p) == true);

    int a2[] = {1, 4, 3, 2, 5, 2};
    p = seed_list(a2, 6);
    assert(s.hasCycle(p) == false);

    int a3[] = {1};
    p = seed_list(a3, 1);
    assert(s.hasCycle(p) == false);

    int a4[] = {1};
    p = seed_list(a4, 1);
    p->next = p;
    assert(s.hasCycle(p) == true);

    assert(s.hasCycle(NULL) == false);
    return 0;
}
