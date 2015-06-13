#include<iostream>
#include<sstream>
#include<queue>
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
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if (root == NULL) {
            return;
        }

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
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


int main(int argc, char *argv[])
{
    Solution s;
    TreeNode* root;
    TreeNode* t1;
    TreeNode* t2;
    TreeNode* t3;
    TreeNode* t4;

    // test seed function
    int tree1[] = {1, 2, 3, -1, -1, 4, -1, -1, -1};
    root = seed_tree(tree1, 9);
    assert(to_str(root) == "1 2 3 NULL NULL 4 NULL NULL NULL");
    s.invertBinaryTree(root);
    assert(to_str(root) == "1 3 2 NULL 4 NULL NULL NULL NULL");

    int tree2[] = {-1};
    root = seed_tree(tree2, 0);
    assert(to_str(root) == "NULL");
    s.invertBinaryTree(root);
    assert(to_str(root) == "NULL");


    int tree3[] = {1, 2, -1, -1, -1};
    root = seed_tree(tree3, 5);
    assert(to_str(root) == "1 2 NULL NULL NULL");
    s.invertBinaryTree(root);
    assert(to_str(root) == "1 NULL 2 NULL NULL");

    return 0;
}
