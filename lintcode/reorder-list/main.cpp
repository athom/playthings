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
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        ListNode* leftPre = NULL;
        ListNode* leftCur = head;
        ListNode* rightPre = NULL;
        ListNode* rightCur = NULL;

        ListNode* prePre = NULL;
        ListNode* pre = NULL;
        ListNode* cur = head;

        while (cur) {
            prePre = pre;
            pre = cur;
            cur = cur->next;
        }

        rightCur = pre;
        rightPre = prePre;

        while (leftCur) {
            ListNode* next = leftCur->next;

            leftCur->next = rightCur;
            rightCur->next = next;
        }
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
    p = s.reorderList(p);
    assert(to_str(p) == "1 4 2 3 NULL\n");

    int a2[] = {1, 2, 3, 4, 5};
    p = seed_list(a2, 5);
    p = s.reorderList(p);
    assert(to_str(p) == "1 5 2 4 3 NULL\n");

    int a3[] = {1, 2};
    p = seed_list(a3, 2);
    p = s.reorderList(p);
    assert(to_str(p) == "1 2 NULL\n");

    int a4[] = {1, 2, 3};
    p = seed_list(a4, 3);
    p = s.reorderList(p);
    assert(to_str(p) == "1 3 2 NULL\n");

    int a5[] = {1};
    p = seed_list(a5, 1);
    p = s.reorderList(p);
    assert(to_str(p) == "1 NULL\n");

    p = s.reorderList(NULL);
    assert(to_str(p) == "NULL\n");
    return 0;
}
