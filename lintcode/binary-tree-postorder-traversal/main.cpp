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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        if (root == NULL) {
            return v;
        }

        vector<int> lv = postorderTraversal(root->left);
        vector<int> rv = postorderTraversal(root->right);

        v.insert(v.end(), lv.begin(), lv.end());
        v.insert(v.end(), rv.begin(), rv.end());
        v.push_back(root->val);
        return v;
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

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode* root;
    vector<int> v;
    int r;

    int tree2[] = {-1};
    root = seed_tree(tree2, 0);
    assert(to_str(root) == "NULL");
    v = s.postorderTraversal(root);
    assert(v.empty());


    int tree3[] = {1, 2, -1, -1, -1};
    root = seed_tree(tree3, 5);
    assert(to_str(root) == "1 2 NULL NULL NULL");
    v = s.postorderTraversal(root);
    assert(to_str_v(v) == "2 1 \n");

    int tree4[] = {1, 2, 3, -1, -1, -1, -1};
    root = seed_tree(tree4, 7);
    assert(to_str(root) == "1 2 3 NULL NULL NULL NULL");
    v = s.postorderTraversal(root);
    assert(to_str_v(v) == "2 3 1 \n");

    v = s.postorderTraversal(NULL);
    assert(v.empty());
    return 0;
}
