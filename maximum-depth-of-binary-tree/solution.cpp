#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL && root->right == NULL) {
            return 1;
        }

        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        return ld > rd ? ld+1:rd+1;
    }
};

int main(int argc, char *argv[])
{
  cout << "hi" << endl;
  TreeNode* t1 = new TreeNode(1);
  TreeNode* t2 = new TreeNode(2);
  TreeNode* t3 = new TreeNode(3);
  TreeNode* t4 = new TreeNode(4);
  TreeNode* t5 = new TreeNode(5);
  TreeNode* t6 = new TreeNode(6);
  TreeNode* t7 = new TreeNode(7);

  t1->left = t2;
  t1->right = t3;
  
  t2->left = t4;
  t2->right = NULL;

  t4->left = NULL;
  t4->right = t7;

  t3->left = t5;
  t3->right = t6;

  Solution* s;
  int depth = s->maxDepth(t1);
  cout << depth << endl;

  return 0;
}
