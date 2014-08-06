#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        if (root == NULL)
        {
            return v;
        }
        vector<int>v_left = inorderTraversal(root->left);
        v_left.push_back(root->val);
        vector<int>v_right = inorderTraversal(root->right);
        v_left.insert(v_left.end(), v_right.begin(), v_right.end());
        return v_left;
    }
};

int main(int argc, char *argv[])
{

    Solution s;
    TreeNode* root = new TreeNode(1);
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(3);
    t1->left = t2;
    root->right = t1;

    vector<int> v = s.inorderTraversal(root);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
