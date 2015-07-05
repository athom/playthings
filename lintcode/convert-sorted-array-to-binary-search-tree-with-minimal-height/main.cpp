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
    TreeNode *sortedArrayToBSTHelper(vector<int> &A, int start, int end) {
        if (end - start == 0) {
            return NULL;
        }

        int mid = start + (end - start)/2;
        TreeNode* node = new TreeNode(A[mid]);
        TreeNode* left = sortedArrayToBSTHelper(A, start, mid);
        TreeNode* right = sortedArrayToBSTHelper(A, mid+1, end);
        node->left = left;
        node->right = right;
        return node;
    }
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        int sz = A.size();
        TreeNode* root = sortedArrayToBSTHelper(A, 0, sz);
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

string to_str(vector<int> s){
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



vector<int> seed_array(const int* a, int len) {
    vector<int> v;
    for (int i = 0; i < len; i++) {
        v.push_back(a[i]);
    }
    return v;
}

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode* root;
    vector<int> v;


    v.clear();
    root = s.sortedArrayToBST(v);
    assert(root == NULL);

    int a0[] = {1};
    v = seed_array(a0, 1);
    assert(to_str(v) == "1 \n");
    root = s.sortedArrayToBST(v);
    assert(to_str(root) == "1 NULL NULL");

    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    v = seed_array(a1, 7);
    assert(to_str(v) == "1 2 3 4 5 6 7 \n");
    root = s.sortedArrayToBST(v);
    assert(to_str(root) == "4 2 6 1 3 5 7 NULL NULL NULL NULL NULL NULL NULL NULL");


    int a2[] = {1, 2, 3, 4, 5};
    v = seed_array(a2, 5);
    root = s.sortedArrayToBST(v);
    assert(to_str(root) == "3 2 5 1 NULL 4 NULL NULL NULL NULL NULL");

    int a3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    v = seed_array(a3, 14);
    root = s.sortedArrayToBST(v);
    assert(to_str(root) == "8 4 12 2 6 10 14 1 3 5 7 9 11 13 NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL NULL");


    return 0;
}
