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
    bool isEqual(TreeNode* T1, TreeNode* T2){
        if (T1 == NULL) {
            return T2 == NULL;
        }
        if (T2 == NULL) {
            return T1 == NULL;
        }
        if (T1->val != T2->val) {
            return false;
        }

        return isEqual(T1->left, T2->left) && isEqual(T1->right, T2->right);
    }
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == NULL) {
            return true;
        }
        if (T1 == NULL) {
            return false;
        }

        if (isEqual(T1, T2)) {
            return true;
        }

        if (isSubtree(T1->left, T2)) {
            return true;
        }

        if (isSubtree(T1->right, T2)) {
            return true;
        }

        return false;
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
    TreeNode* root2;
    bool r;


    r = s.isSubtree(NULL, NULL);
    assert(r == true);

    int tree3[] = {2, 1, -1, -1, -1};
    root = seed_tree(tree3, 5);
    assert(to_str(root) == "2 1 NULL NULL NULL");
    r = s.isSubtree(root, NULL);
    assert(r == true);
    int tree33[] = {1, -1, -1};
    root2 = seed_tree(tree33, 3);
    assert(to_str(root2) == "1 NULL NULL");
    r = s.isSubtree(root, root2);
    assert(r == true);
    int tree333[] = {2, -1, -1};
    root2 = seed_tree(tree333, 3);
    r = s.isSubtree(root, root2);
    assert(r == false);

    //     2
    //    / \
    //   1   4
    //      /
    //     3
    int tree4[] = {2, 1, 4, -1, -1, 3, -1, -1, -1};
    root = seed_tree(tree4, 9);
    assert(to_str(root) == "2 1 4 NULL NULL 3 NULL NULL NULL");
    int tree44[] = { 4, 3, -1, -1, -1};
    root2 = seed_tree(tree44, 5);
    r = s.isSubtree(root, root2);
    assert(r == true);
    int tree444[] = { 4, -1, -1};
    root2 = seed_tree(tree444, 3);
    r = s.isSubtree(root, root2);
    assert(r == false);

    //     2
    //      \
    //       4
    //      /
    //     3
    int treeA[] = {2, -1, 4, 3, -1, -1, -1};
    root = seed_tree(treeA, 7);
    assert(to_str(root) == "2 NULL 4 3 NULL NULL NULL");
    int treeAA[] = { 4, 3, -1, -1, -1};
    root2 = seed_tree(treeAA, 5);
    r = s.isSubtree(root, root2);
    assert(r == true);
    int treeAAA[] = { 4, -1, -1};
    root2 = seed_tree(treeAAA, 3);
    r = s.isSubtree(root, root2);
    assert(r == false);

    //          2
    //         / \
    //        1   6
    //            /
    //           4
    int tree5[] = {2, 1, 6, -1, -1, 4, -1, -1, -1};
    root = seed_tree(tree5, 9);
    assert(to_str(root) == "2 1 6 NULL NULL 4 NULL NULL NULL");
    root2 = seed_tree(tree5, 9);
    r = s.isSubtree(root, root2);
    assert(r == true);
    int tree55[] = { 4, -1, -1};
    root2 = seed_tree(tree55, 3);
    assert(r == true);
    int tree555[] = { 6, -1, -1};
    root2 = seed_tree(tree555, 3);
    assert(r == true);


    //           2
    //          / \
    //         1   6
    //            / \
    //           4   5
    int tree6[] = {2, 1, 6, -1, -1, 4, 5, -1, -1, -1, -1};
    root = seed_tree(tree6, 11);
    assert(to_str(root) == "2 1 6 NULL NULL 4 5 NULL NULL NULL NULL");
    int tree66[] = { 6, -1, -1};
    root2 = seed_tree(tree66, 3);
    r = s.isSubtree(root, root2);
    assert(r == false);
    int tree666[] = { 6, 4, 5, -1, -1, -1, -1};
    root2 = seed_tree(tree666, 7);
    r = s.isSubtree(root, root2);
    assert(r == true);
    int tree6666[] = { 6, 4, -1, -1, -1};
    root2 = seed_tree(tree6666, 5);
    r = s.isSubtree(root, root2);
    assert(r == false);


    ////          10
    ////         / \
    ////        5   15
    ////           / \
    ////          6   20
    //int tree7[] = {10, 5, 15, -1, -1, 6, 20, -1, -1, -1, -1};
    //root = seed_tree(tree7, 11);
    //assert(to_str(root) == "10 5 15 NULL NULL 6 20 NULL NULL NULL NULL");
    //r = s.isBalanced(root);
    //assert(r == true);

    ////          10
    ////         /  \
    ////        5    15
    ////         \     \
    ////         11     20
    //int tree8[] = {10, 5, 15, -1, 11, -1, 20, -1, -1, -1, -1};
    //root = seed_tree(tree8, 11);
    //assert(to_str(root) == "10 5 15 NULL 11 NULL 20 NULL NULL NULL NULL");
    //r = s.isBalanced(root);
    //assert(r == true);

    ////          10
    ////         /  \
    ////        5    15
    ////         \     \
    ////          9     20
    //int tree9[] = {10, 5, 15, -1, 9, -1, 20, -1, -1, -1, -1};
    //root = seed_tree(tree9, 11);
    //assert(to_str(root) == "10 5 15 NULL 9 NULL 20 NULL NULL NULL NULL");
    //r = s.isBalanced(root);
    //assert(r == true);

    ////          10
    ////         /  \
    ////        5    -15
    ////         \     \
    ////          9     20
    //int tree10[] = {10, 5, -15, -1, 9, -1, 20, -1, -1, -1, -1};
    //root = seed_tree(tree10, 11);
    //assert(to_str(root) == "10 5 -15 NULL 9 NULL 20 NULL NULL NULL NULL");
    //r = s.isBalanced(root);
    //assert(r == true);

    ////          10
    ////         /  \
    ////        5    -15
    ////       / \     \
    ////     -8   9     20
    ////    /  \
    ////   6    4
    //int tree11[] = {10, 5, -15, -8, 9, -1, 20, 6, 4, -1, -1, -1, -1, -1, -1, -1, -1};
    //root = seed_tree(tree11, 17);
    //assert(to_str(root) == "10 5 -15 -8 9 NULL 20 6 4 NULL NULL NULL NULL NULL NULL NULL NULL");
    //r = s.isBalanced(root);
    //assert(r == true);

    //// -10,-20,#,#,-31,-24,-5,#,#,-6,-7,-8,-9
    ////                 -10
    ////                 /
    ////               -20
    ////                 \
    ////                 -31
    ////                 /  \
    ////               -24   -5
    ////                     / \
    ////                   -6  -7
    ////                   / \
    ////                 -8  -9
    //int tree12[] = {-10, -20, -1, -1, -31, -24, -5, -1, -1, -6, -7, -8, -9, -1, -1, -1, -1, -1, -1};
    //root = seed_tree(tree12, 17);
    //assert(to_str(root) == "-10 -20 NULL NULL -31 -24 -5 NULL NULL -6 -7 -8 -9 NULL NULL NULL NULL NULL NULL");
    //r = s.isBalanced(root);
    //assert(r == false);

    ////          10
    ////         /  \
    ////        5    -15
    ////       /       \
    ////     -8         20
    ////    /  \
    ////   6    4
    //int tree13[] = {10, 5, -15, -8, -1, -1, 20, 6, 4, -1, -1, -1, -1, -1, -1};
    //root = seed_tree(tree13, 15);
    //assert(to_str(root) == "10 5 -15 -8 NULL NULL 20 6 4 NULL NULL NULL NULL NULL NULL");
    //r = s.isBalanced(root);
    //assert(r == false);

    return 0;
}
