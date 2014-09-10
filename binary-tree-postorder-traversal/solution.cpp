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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        if (root == NULL)
        {
            return v;
        }
        vector<int>v_left = postorderTraversal(root->left);
        vector<int>v_right = postorderTraversal(root->right);
        v.insert(v.end(), v_left.begin(), v_left.end());
        v.insert(v.end(), v_right.begin(), v_right.end());
        v.push_back(root->val);
        return v;
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

    vector<int> v = s.postorderTraversal(root);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
