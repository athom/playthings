//#include<>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
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
    int mod(int x, int m) {
        if (m == 0 || m == 1) {
            return 0;
        }

        int r = x % m;
        if (r < 0) {
            r = m + r;
        }
        return r;
    }
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        vector<ListNode*> h;

        int sz = hashTable.size();
        if (sz == 0) {
            return h;
        }
        for (int i = 0; i < 2*sz; ++i) {
            h.push_back(NULL);
        }

        for (int i = 0; i < sz; ++i) {
            if (hashTable[i] == NULL) {
                continue;
            }

            ListNode* node = hashTable[i];
            ListNode* cur = node;
            while (cur) {
                int newIndex = mod(cur->val, 2*sz);
                if (h[newIndex] == NULL) {
                    h[newIndex] = cur;
                } else {
                    ListNode* pre = NULL;
                    ListNode* newCur = h[newIndex];
                    while (newCur) {
                        pre = newCur;
                        newCur = newCur->next;
                    }
                    pre->next = cur;
                }

                ListNode* next = cur->next;
                cur->next = NULL;
                cur = next;
            }
        }

        return h;
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
    vector<ListNode*> h;
    vector<ListNode*> hh;

    int a1[] = {21, 9};
    ListNode* p1 = seed_list(a1, 2);
    assert(to_str(p1) == "21 9 NULL\n");
    h.push_back(NULL);
    h.push_back(p1);
    int a2[] = {14};
    ListNode* p2 = seed_list(a2, 1);
    assert(to_str(p2) == "14 NULL\n");
    h.push_back(p2);
    h.push_back(NULL);


    hh = s.rehashing(h);
    assert(hh[0] == NULL);
    assert(hh[1] != NULL);
    assert(hh[2] == NULL);
    assert(hh[3] == NULL);
    assert(hh[4] == NULL);
    assert(hh[5] != NULL);
    assert(hh[6] != NULL);
    assert(hh[7] == NULL);
    assert(hh[1]->val == 9);
    assert(hh[5]->val == 21);
    assert(hh[6]->val == 14);

    h.clear();
    int a3[] = {29, 5};
    ListNode* p3 = seed_list(a3, 2);
    assert(to_str(p3) == "29 5 NULL\n");
    h.push_back(NULL);
    h.push_back(NULL);
    h.push_back(p3);
    hh = s.rehashing(h);
    assert(hh[0] == NULL);
    assert(hh[1] == NULL);
    assert(hh[2] == NULL);
    assert(hh[3] == NULL);
    assert(hh[4] == NULL);
    assert(hh[5] != NULL);
    assert(hh[5]->val == 29);
    assert(hh[5]->next->val == 5);
    assert(hh[5]->next->next == NULL);

    h.clear();
    int a4[] = {42, 32};
    ListNode* p4 = seed_list(a4, 2);
    int a5[] = {-7};
    ListNode* p5 = seed_list(a5, 1);
    h.push_back(NULL);
    h.push_back(NULL);
    h.push_back(p4);
    h.push_back(p5);
    h.push_back(NULL);

    hh = s.rehashing(h);
    assert(hh[0] == NULL);
    assert(hh[1] == NULL);
    assert(hh[2] != NULL);
    assert(hh[3] != NULL);
    assert(hh[4] == NULL);
    assert(hh[5] == NULL);
    assert(hh[6] == NULL);
    assert(hh[7] == NULL);
    assert(hh[8] == NULL);
    assert(hh[9] == NULL);
    assert(hh[2]->val == 42);
    assert(hh[2]->next->val == 32);
    assert(hh[3]->val == -7);

    return 0;
}
