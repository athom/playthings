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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode* newListHead = NULL;
        ListNode* newListCur = NULL;

        ListNode* cur;
        ListNode* pre;
        ListNode* pMinCur;
        ListNode* pMinPre;
        int min;

        cur = head;
        pre = NULL;
        pMinCur = cur;
        pMinPre = pre;
        while (cur) {

            min = cur->val;
            // find the min node
            while (cur) {
                if (cur->val < min) {
                    min = cur->val;
                    pMinCur = cur;
                    pMinPre = pre;
                }
                pre = cur;
                cur = cur->next;
            }

            // move min node out of old list
            if (pMinPre == NULL) {
                head = pMinCur->next;
            }else{
                pMinPre->next = pMinCur->next;
            }

            // move to new list;
            if (newListCur == NULL) {
                newListHead = pMinCur;
            }else{
                newListCur->next = pMinCur;
            }
            newListCur = pMinCur;

            cur = head;
            pre = NULL;
            pMinCur = cur;
            pMinPre = pre;
        }

        return newListHead;
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
    assert(to_str(p) == "1 4 3 2 5 2 NULL\n");
    p = s.insertionSortList(p);
    assert(to_str(p) == "1 2 2 3 4 5 NULL\n");

    int a2[] = {1};
    p = seed_list(a2, 1);
    assert(to_str(p) == "1 NULL\n");
    p = s.insertionSortList(p);
    assert(to_str(p) == "1 NULL\n");

    int a3[] = {1, 2, 3};
    p = seed_list(a3, 3);
    assert(to_str(p) == "1 2 3 NULL\n");
    p = s.insertionSortList(p);
    assert(to_str(p) == "1 2 3 NULL\n");

    int a4[] = {3, 2, 1};
    p = seed_list(a4, 3);
    assert(to_str(p) == "3 2 1 NULL\n");
    p = s.insertionSortList(p);
    assert(to_str(p) == "1 2 3 NULL\n");

    p = s.insertionSortList(NULL);
    assert(to_str(p) == "NULL\n");
    return 0;
}
