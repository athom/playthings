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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if (node == NULL) {
           return;
        }
        if (node->next == NULL) {
            node = NULL;
            return;
        }
        node->val = node->next->val;
        node->next = node->next->next;
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

    int a1[] = {1, 4, 3, 2, 5, 2};
    p = seed_list(a1, 6);
    assert(to_str(p) == "1 4 3 2 5 2 NULL\n");
    pd = p->next->next;
    s.deleteNode(pd);
    assert(to_str(p) == "1 4 2 5 2 NULL\n");


    //int a2[] = {1, 2, 3};
    //p = seed_list(a2, 3);
    //assert(to_str(p) == "1 2 3 NULL\n");
    //pd = p->next->next;
    //s.deleteNode(pd);
    //assert(to_str(p) == "1 2 NULL\n");

    int a3[] = {1, 2, 3};
    p = seed_list(a3, 3);
    assert(to_str(p) == "1 2 3 NULL\n");
    pd = p;
    s.deleteNode(pd);
    assert(to_str(p) == "2 3 NULL\n");


    p = NULL;
    s.deleteNode(NULL);
    assert(to_str(p) == "NULL\n");
    return 0;
}
