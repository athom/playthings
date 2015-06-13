//#include<>
#include<iostream>
#include<sstream>
#include<queue>
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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        queue<ListNode*> q;
        // write your code here
        if (head == NULL) {
            return NULL;
        }

        if (k == 0) {
            return head;
        }

        ListNode* maker;
        ListNode* cur = head;
        while (cur) {
            if (k > 0 && q.size() == k+1) {
                q.pop();
            }
            q.push(cur);
            cur = cur->next;
        }

        if (q.size() != k+1) {
            // cuculate the new k, mod by k and make sure it was not minus
            int listCount = q.size();
            k %= listCount;
            if (k < 0 ) {
                k = listCount + k;
            }
            if (k == 0) {
                return head;
            }

            // clear queue, sucks there is not q.clear() method.
            while (!q.empty()) {
                q.pop();
            }
            cur = head;
            while (cur) {
                if (q.size() == k+1) {
                    q.pop();
                }
                q.push(cur);
                cur = cur->next;
            }
        }

        ListNode* newTail = q.front();
        newTail->next = NULL;

        q.pop();
        ListNode* newHead = q.front();
        if (q.empty()) {
            newHead->next = head;
        } else {
            q.back()->next = head;
        }

        return newHead;
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

    int a1[] = {1, 2, 3, 4, 5};
    p = seed_list(a1, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.rotateRight(p, 2);
    assert(to_str(p) == "4 5 1 2 3 NULL\n");

    int a2[] = {1, 2, 3, 4, 5};
    p = seed_list(a2, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.rotateRight(p, 4);
    assert(to_str(p) == "2 3 4 5 1 NULL\n");

    int a3[] = {1, 2, 3, 4, 5};
    p = seed_list(a3, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.rotateRight(p, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");

    int a4[] = {1, 2, 3, 4, 5};
    p = seed_list(a4, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.rotateRight(p, 6);
    assert(to_str(p) == "5 1 2 3 4 NULL\n");

    int a5[] = {1, 2, 3, 4, 5};
    p = seed_list(a5, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.rotateRight(p, 31);
    assert(to_str(p) == "5 1 2 3 4 NULL\n");

    int a6[] = {1, 2, 3, 4, 5};
    p = seed_list(a6, 5);
    assert(to_str(p) == "1 2 3 4 5 NULL\n");
    p = s.rotateRight(p, -1);
    assert(to_str(p) == "2 3 4 5 1 NULL\n");


    int a7[] = {1};
    p = seed_list(a7, 1);
    assert(to_str(p) == "1 NULL\n");
    p = s.rotateRight(p, 1);
    assert(to_str(p) == "1 NULL\n");

    int a8[] = {1};
    p = seed_list(a8, 1);
    assert(to_str(p) == "1 NULL\n");
    p = s.rotateRight(p, 0);
    assert(to_str(p) == "1 NULL\n");

    int a9[] = {1};
    p = seed_list(a9, 1);
    assert(to_str(p) == "1 NULL\n");
    p = s.rotateRight(p, 2);
    assert(to_str(p) == "1 NULL\n");

    int a10[] = {1};
    p = seed_list(a10, 1);
    assert(to_str(p) == "1 NULL\n");
    p = s.rotateRight(p, -1);
    assert(to_str(p) == "1 NULL\n");


    p = s.rotateRight(NULL, 1);
    assert(to_str(p) == "NULL\n");

    p = s.rotateRight(NULL, 0);
    assert(to_str(p) == "NULL\n");

    p = s.rotateRight(NULL, -1);
    assert(to_str(p) == "NULL\n");
    return 0;
}
