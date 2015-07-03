//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        map<RandomListNode*, int>m_ptr2index;
        map<int, RandomListNode*>m_index2ptr;
        RandomListNode* cur = head;
        int count = 0;
        while (cur) {
            m_ptr2index[cur] = count;
            cur = cur->next;
            count++;
        }

        count = 0;
        cur = head;
        RandomListNode* pre = NULL;
        RandomListNode* newHead = NULL;
        while (cur) {
            RandomListNode* newNode = new RandomListNode(cur->label);
            if (pre == NULL) {
                newHead = newNode;
            } else {
                pre->next = newNode;
            }
            pre = newNode;
            cur = cur->next;
            m_index2ptr[count] = pre;
            count++;
        }

        cur = head;
        RandomListNode* newCur = newHead;
        while (cur) {
            if (cur->random == NULL) {
                newCur->random = NULL;
            } else {
                int index = m_ptr2index.at(cur->random);
                RandomListNode* toBePointed = m_index2ptr.at(index);
                newCur->random = toBePointed;
            }

            newCur = newCur->next;
            cur = cur->next;
        }

        return newHead;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    RandomListNode* root;
    RandomListNode* node;
    vector<int> v;
    int r;

    root = s.copyRandomList(NULL);
    assert(root == NULL);

    RandomListNode* node1 = new RandomListNode(1);
    RandomListNode* node2 = new RandomListNode(2);
    RandomListNode* node3 = new RandomListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node1->random = node3;
    node2->random = NULL;
    node3->random = node2;

    root = s.copyRandomList(node1);
    node1 = root;
    node2 = root->next;
    node3 = root->next->next;
    assert(node1->label == 1);
    assert(node2->label == 2);
    assert(node3->label == 3);

    assert(node1->random == node3);
    assert(node2->random == NULL);
    assert(node3->random == node2);


    return 0;
}
