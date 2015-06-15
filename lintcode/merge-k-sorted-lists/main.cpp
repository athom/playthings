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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode* >& lists) {
        // write your code here
        ListNode* head = NULL;
        ListNode* cur = NULL;
        if (lists.size() == 0) {
            return head;
        }

        int MAXINT = ~(1<<(sizeof(int)*8-1)); // +INF
        while (!lists.empty()) {
            int minVal = MAXINT;
            ListNode* minNode = NULL;
            int index = -1;

            bool meetNullHeader = false;
            for (vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); it++) {
                if (*it == NULL) {
                    lists.erase(it);
                    meetNullHeader = true;
                    break;
                }

                if ((*it)->val < minVal) {
                    minVal = (*it)->val;
                    minNode = *it;
                    index = it - lists.begin();
                }
            }
            if (meetNullHeader) {
                continue;
            }

            if (minNode) {
                if (head == NULL) {
                    head = minNode;
                    cur = minNode;
                } else {
                    cur->next = minNode;
                    cur = cur->next;
                }
                lists[index] = minNode->next;
            }
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
    ListNode* p1;
    ListNode* p2;
    ListNode* p3;
    vector<ListNode*> v;


    int bbb1[] = {6, 8, 8, 10};
    p1 = seed_list(bbb1, 4);
    int bbb2[] = {1, 2, 3, 7};
    p2 = seed_list(bbb2, 4);
    v.clear();
    v.push_back(p1);
    v.push_back(p2);
    p = s.mergeKLists(v);
    assert(to_str(p) == "1 2 3 6 7 8 8 10 NULL\n");

    int a1[] = {6, 8, 8, 10};
    p1 = seed_list(a1, 4);
    int b1[] = {1, 2, 3, 7};
    p2 = seed_list(b1, 4);
    int c1[] = {2, 3, 5, 8};
    p3 = seed_list(c1, 4);
    v.clear();
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    p = s.mergeKLists(v);
    assert(to_str(p) == "1 2 2 3 3 5 6 7 8 8 8 10 NULL\n");

    int a2[] = {6, 8, 8, 10};
    p1 = seed_list(a2, 4);
    v.clear();
    v.push_back(p1);
    p = s.mergeKLists(v);
    assert(to_str(p) == "6 8 8 10 NULL\n");


    int a3[] = {1};
    p1 = seed_list(a3, 1);
    int b3[] = {2};
    p2 = seed_list(b3, 1);
    int c3[] = {3};
    p3 = seed_list(c3, 1);
    v.clear();
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    p = s.mergeKLists(v);
    assert(to_str(p) == "1 2 3 NULL\n");

    int a4[] = {1, 3};
    p1 = seed_list(a4, 2);
    int b4[] = {3};
    p2 = seed_list(b4, 1);
    v.clear();
    v.push_back(NULL);
    v.push_back(p1);
    v.push_back(NULL);
    v.push_back(p2);
    p = s.mergeKLists(v);
    assert(to_str(p) == "1 3 3 NULL\n");

    v.clear();
    v.push_back(NULL);
    v.push_back(NULL);
    v.push_back(NULL);
    p = s.mergeKLists(v);
    assert(to_str(p) == "NULL\n");

    v.clear();
    p = s.mergeKLists(v);
    assert(to_str(p) == "NULL\n");
    return 0;
}
