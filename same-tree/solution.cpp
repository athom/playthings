#include <iostream>
using namespace std;

/**
  Definition for binary tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
        {
            return true;
        }

        if(p != NULL && q != NULL)
        {
            if (p->val != q->val)
            {
                return false;
            }

            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    t1->right = t2;
    t2->left = t4;
    t4->right = t3;

    TreeNode* d1 = new TreeNode(1);
    TreeNode* d2 = new TreeNode(2);
    TreeNode* d3 = new TreeNode(3);
    TreeNode* d4 = new TreeNode(4);
    d1->right = d4;
    d4->left = d2;
    d2->right = d3;



    Solution* s;
    bool same = s->isSameTree(t1, d1);
    cout << same << endl;
    return 0;
}
