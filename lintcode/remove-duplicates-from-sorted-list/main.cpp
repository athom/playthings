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
        map<int, bool> dup;
        ListNode* pre = NULL;
        ListNode* cur = head;

        while (cur) {
            // duplicated elements, remove it;
            if (dup.find(cur->val) != dup.end()) {
                ListNode* next = cur->next;
                pre->next = next;
                delete cur;
                cur = next;
                continue;
            }

            dup[cur->val] = true;
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

    int bbb1[] = {1, 1, 2};
    p1 = seed_list(bbb1, 3);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "1 2 NULL\n");

    int bb1[] = {1, 1, 2, 3, 3};
    p1 = seed_list(bb1, 5);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "1 2 3 NULL\n");

    int b1[] = {1, 1, 1};
    p1 = seed_list(b1, 3);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "1 NULL\n");

    int b2[] = {1};
    p1 = seed_list(b2, 1);
    p = s.deleteDuplicates(p1);
    assert(to_str(p) == "1 NULL\n");

    p = s.deleteDuplicates(NULL);
    assert(to_str(p) == "NULL\n");
    return 0;
}
