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
     * @return: The node where the cycle begins.
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        map<ListNode*, bool> m;
        ListNode* cur = head;
        while (cur && m.find(cur) == m.end()) {
            m[cur] = true;
            cur = cur->next;
        }

        return cur;
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
    assert(s.detectCycle(p) == p->next->next);

    int a2[] = {1, 4, 3, 2, 5, 2};
    p = seed_list(a2, 6);
    assert(s.detectCycle(p) == NULL);

    int a3[] = {1};
    p = seed_list(a3, 1);
    assert(s.detectCycle(p) == NULL);

    int a4[] = {1};
    p = seed_list(a4, 1);
    p->next = p;
    assert(s.detectCycle(p) == p);

    assert(s.detectCycle(NULL) == NULL);
    return 0;
}
