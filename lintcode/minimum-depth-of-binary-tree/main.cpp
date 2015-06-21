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
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return minDepthHelper(root);
    }

    int minDepthHelper(TreeNode *root) {
        if (root == NULL) {
            return ~(1<<31);
        }

        if (root->left == NULL && root->right == NULL) {
            return 1;
        }

        int leftH = minDepthHelper(root->left);
        int rightH = minDepthHelper(root->right);

        int minH = leftH < rightH ? leftH : rightH;
        return minH + 1;
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
    int r;

    int tree2[] = {1, -1, -1};
    root = seed_tree(tree2, 3);
    assert(to_str(root) == "1 NULL NULL");
    r = s.minDepth(root);
    assert(r == 1);

    int tree3[] = {1, 2, -1, -1, -1};
    root = seed_tree(tree3, 5);
    assert(to_str(root) == "1 2 NULL NULL NULL");
    r = s.minDepth(root);
    assert(r == 2);

    int tree4[] = {1, 2, 3, -1, -1, -1, -1};
    root = seed_tree(tree4, 7);
    assert(to_str(root) == "1 2 3 NULL NULL NULL NULL");
    r = s.minDepth(root);
    assert(r == 2);

    //       1
    //      / \
    //   null  2
    //        / \
    //       3   null
    //      / \
    //    null 4
    //        / \
    //      null null
    int tree5[] = {1, -1, 2, 3, -1, -1, 4, -1, -1};
    root = seed_tree(tree5, 9);
    assert(to_str(root) == "1 NULL 2 3 NULL NULL 4 NULL NULL");
    r = s.minDepth(root);
    assert(r == 4);

    //       1
    //      / \
    //   null  2
    //        / \
    //       3   null
    //      / \
    //    null null
    int tree6[] = {1, -1, 2, 3, -1, -1, -1};
    root = seed_tree(tree6, 7);
    assert(to_str(root) == "1 NULL 2 3 NULL NULL NULL");
    r = s.minDepth(root);
    assert(r == 3);

    //       1
    //      / \
    //   null  2
    //        / \
    //       3   5
    //      / \
    //    null 4
    //        / \
    //      null null
    int tree7[] = {1, -1, 2, 3, 5, -1, 4, -1, -1, -1, -1};
    root = seed_tree(tree7, 11);
    assert(to_str(root) == "1 NULL 2 3 5 NULL 4 NULL NULL NULL NULL");
    r = s.minDepth(root);
    assert(r == 3);

    //       1
    //      / \
    //     6   2
    //        / \
    //       3   5
    //      / \
    //    null 4
    //        / \
    //      null null
    int tree8[] = {1, 6, 2, -1, -1, 3, 5, -1, 4, -1, -1, -1, -1};
    root = seed_tree(tree8, 13);
    assert(to_str(root) == "1 6 2 NULL NULL 3 5 NULL 4 NULL NULL NULL NULL");
    r = s.minDepth(root);
    assert(r == 2);

    r = s.minDepth(NULL);
    assert(r == 0);
    return 0;
}
