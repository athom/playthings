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
    vector<int> depthAndBalanced(TreeNode* root) {
        vector<int> v;
        if (root == NULL) {
            v.push_back(0);
            v.push_back(1);
            return v;
        }
        v.push_back(0);
        v.push_back(0);

        vector<int> Lv = depthAndBalanced(root->left);
        vector<int> Rv = depthAndBalanced(root->right);

        int r = Lv[0] > Rv[0] ? Lv[0] : Rv[0];
        v[0] = r + 1;

        if (Lv[1] == 0 || Rv[1] == 0) {
            v[1] = 0;
            return v;
        }

        if (abs(Lv[0] - Rv[0]) > 1) {
            v[1] = 0;
        } else {
            v[1] = 1;
        }
        //cout << "root: " << root->val
            //<< " left depth:" << Lv[0]
            //<< " right depth:" << Rv[0]
            //<< " left balance:" << Lv[1]
            //<< " right balance:" << Rv[1]
            //<< " root depth:" << v[0]
            //<< " balanced:" << v[1]
            //<< endl;
        return v;
    }
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        vector<int> v = depthAndBalanced(root);
        return v[1] == 1;
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
    bool r;


    r = s.isBalanced(NULL);
    assert(r == true);

    int tree3[] = {2, 1, -1, -1, -1};
    root = seed_tree(tree3, 5);
    assert(to_str(root) == "2 1 NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == true);

    //     2
    //    / \
    //   1   4
    //      /
    //     3
    int tree4[] = {2, 1, 4, -1, -1, 3, -1, -1, -1};
    root = seed_tree(tree4, 9);
    assert(to_str(root) == "2 1 4 NULL NULL 3 NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == true);

    //     2
    //      \
    //       4
    //      /
    //     3
    int tree44[] = {2, -1, 4, 3, -1, -1, -1};
    root = seed_tree(tree44, 7);
    assert(to_str(root) == "2 NULL 4 3 NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == false);
    return 0;

    //          2
    //         / \
    //        1   6
    //            /
    //           4
    int tree5[] = {2, 1, 6, -1, -1, 4, -1, -1, -1};
    root = seed_tree(tree5, 9);
    assert(to_str(root) == "2 1 6 NULL NULL 4 NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == true);

    //           2
    //          / \
    //         1   6
    //        / \
    //       4   5
    int tree6[] = {2, 1, 6, -1, -1, 4, 5, -1, -1, -1, -1};
    root = seed_tree(tree6, 11);
    assert(to_str(root) == "2 1 6 NULL NULL 4 5 NULL NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == true);


    //          10
    //         / \
    //        5   15
    //           / \
    //          6   20
    int tree7[] = {10, 5, 15, -1, -1, 6, 20, -1, -1, -1, -1};
    root = seed_tree(tree7, 11);
    assert(to_str(root) == "10 5 15 NULL NULL 6 20 NULL NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == true);

    //          10
    //         /  \
    //        5    15
    //         \     \
    //         11     20
    int tree8[] = {10, 5, 15, -1, 11, -1, 20, -1, -1, -1, -1};
    root = seed_tree(tree8, 11);
    assert(to_str(root) == "10 5 15 NULL 11 NULL 20 NULL NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == true);

    //          10
    //         /  \
    //        5    15
    //         \     \
    //          9     20
    int tree9[] = {10, 5, 15, -1, 9, -1, 20, -1, -1, -1, -1};
    root = seed_tree(tree9, 11);
    assert(to_str(root) == "10 5 15 NULL 9 NULL 20 NULL NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == true);

    //          10
    //         /  \
    //        5    -15
    //         \     \
    //          9     20
    int tree10[] = {10, 5, -15, -1, 9, -1, 20, -1, -1, -1, -1};
    root = seed_tree(tree10, 11);
    assert(to_str(root) == "10 5 -15 NULL 9 NULL 20 NULL NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == true);

    //          10
    //         /  \
    //        5    -15
    //       / \     \
    //     -8   9     20
    //    /  \
    //   6    4
    int tree11[] = {10, 5, -15, -8, 9, -1, 20, 6, 4, -1, -1, -1, -1, -1, -1, -1, -1};
    root = seed_tree(tree11, 17);
    assert(to_str(root) == "10 5 -15 -8 9 NULL 20 6 4 NULL NULL NULL NULL NULL NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == true);

    // -10,-20,#,#,-31,-24,-5,#,#,-6,-7,-8,-9
    //                 -10
    //                 /
    //               -20
    //                 \
    //                 -31
    //                 /  \
    //               -24   -5
    //                     / \
    //                   -6  -7
    //                   / \
    //                 -8  -9
    int tree12[] = {-10, -20, -1, -1, -31, -24, -5, -1, -1, -6, -7, -8, -9, -1, -1, -1, -1, -1, -1};
    root = seed_tree(tree12, 17);
    assert(to_str(root) == "-10 -20 NULL NULL -31 -24 -5 NULL NULL -6 -7 -8 -9 NULL NULL NULL NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == false);

    //          10
    //         /  \
    //        5    -15
    //       /       \
    //     -8         20
    //    /  \
    //   6    4
    int tree13[] = {10, 5, -15, -8, -1, -1, 20, 6, 4, -1, -1, -1, -1, -1, -1};
    root = seed_tree(tree13, 15);
    assert(to_str(root) == "10 5 -15 -8 NULL NULL 20 6 4 NULL NULL NULL NULL NULL NULL");
    r = s.isBalanced(root);
    assert(r == false);

    return 0;
}
