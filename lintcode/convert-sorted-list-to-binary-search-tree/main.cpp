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

/**
 * Definition of TreeNode:
 */
class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        }
};

class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return pre;
    }
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            TreeNode* node = new TreeNode(head->val);
            return node;
        }

        ListNode* tail = findMiddle(head);
        ListNode* mid = tail->next;
        TreeNode* root = new TreeNode(mid->val);
        ListNode* right = mid->next;
        tail->next = NULL;
        ListNode* left = head;

        TreeNode* leftChild = sortedListToBST(left);
        TreeNode* rightChild = sortedListToBST(right);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
};

TreeNode* seed_tree(const int* a, int len) {
    TreeNode* root = NULL;
    pair<TreeNode*, bool> p;
    queue<pair<TreeNode*, bool> > q;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == -1) {
            if (!q.empty()) {
                q.pop();
            }
            continue;
        }

        TreeNode* n = new TreeNode(a[i]);
        if (q.empty()) {
            p = make_pair(n, true);
            q.push(p);
            p = make_pair(n, false);
            q.push(p);
            root = n;
            continue;
        }

        p = q.front();
        if (p.second) {
            p.first->left = n;
        }else{
            p.first->right = n;
        }
        q.pop();

        p = make_pair(n, true);
        q.push(p);
        p = make_pair(n, false);
        q.push(p);
    }

    return root;
}

string to_str_v(vector<int> s){
    ostringstream os;
    int i = 0;
    while(i<s.size()){
        os << s[i] << " ";
        i++;
    }
    os << endl;
    return os.str();
}

string to_str(TreeNode* t){
    queue<TreeNode*> q;
    ostringstream os;
    if (t == NULL) {
        os << "NULL";
        return os.str();
    }
    q.push(t);
    while (!q.empty()) {
        TreeNode* p = q.front();
        if (p == NULL) {
            if (q.size() == 1) {
                os << "NULL";
            } else {
                os << "NULL" << " ";
            }
            q.pop();
            continue;
        }
        os << p->val << " ";
        q.pop();
        q.push(p->left);
        q.push(p->right);
    }

    return os.str();
}

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
    TreeNode* root;
    ListNode* head;

    root = s.sortedListToBST(NULL);
    assert(root == NULL);

    int a0[] = {1};
    head = seed_list(a0, 1);
    assert(to_str(head) == "1 NULL\n");
    root = s.sortedListToBST(head);
    assert(to_str(root) == "1 NULL NULL");

    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    head = seed_list(a1, 7);
    assert(to_str(head) == "1 2 3 4 5 6 7 NULL\n");
    root = s.sortedListToBST(head);
    assert(to_str(root) == "4 2 6 1 3 5 7 NULL NULL NULL NULL NULL NULL NULL NULL");


    int a2[] = {1, 2, 3, 4, 5};
    head = seed_list(a2, 5);
    root = s.sortedListToBST(head);
    assert(to_str(root) == "3 2 5 1 NULL 4 NULL NULL NULL NULL NULL");

    int a3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    head = seed_list(a3, 14);
    root = s.sortedListToBST(head);
    assert(to_str(root) == "8 4 12 2 6 10 14 1 3 5 7 9 11 13 NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL");


    return 0;
}
