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

struct Result {
    TreeNode* Node;
    bool AInRoot;
    bool BInRoot;
};

class Solution {
public:
    void debug(Result r) {
        return;
        cout << "node: " << r.Node
            << " AInRoot: " << r.AInRoot
            << " BInRoot: " << r.BInRoot
            << endl;
    }

    Result helper(TreeNode *root, TreeNode *A, TreeNode *B) {
        Result r;
        r.Node = NULL;
        r.AInRoot = false;
        r.BInRoot = false;
        if (root == NULL || A == NULL || B == NULL) {
            debug(r);
            return r;
        }

        if (root->left == NULL && root->right == NULL) {
            r.AInRoot = root == A;
            r.BInRoot = root == B;
            if (r.AInRoot && r.BInRoot) {
                r.Node = root;
            }
            debug(r);
            return r;
        }

        Result L = helper(root->left, A, B);
        if (L.Node) {
            r.Node = L.Node;
            debug(r);
            return r;
        }
        Result R = helper(root->right, A, B);
        if (R.Node) {
            r.Node = R.Node;
            debug(r);
            return r;
        }

        r.AInRoot = L.AInRoot || R.AInRoot || A == root;
        r.BInRoot = L.BInRoot || R.BInRoot || B == root;
        if (r.AInRoot && r.BInRoot) {
            r.Node = root;
        }
        debug(r);
        return r;
    }
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        if (root == NULL || A == NULL  || B == NULL) {
            return NULL;
        }

        Result r = helper(root, A, B);
        return r.Node;
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
    TreeNode* node1;
    TreeNode* node2;
    TreeNode* node;

    node = s.lowestCommonAncestor(NULL, NULL, NULL);
    assert(node == NULL);

    int treeA1[] = {4, 3, 7, -1, -1, 5, 6, -1, -1, -1, -1};
    root = seed_tree(treeA1, 11);
    assert(to_str(root) == "4 3 7 NULL NULL 5 6 NULL NULL NULL NULL");
    node1 = root->left;
    node2 = root->right->left;
    node = s.lowestCommonAncestor(root, node1, node2);
    assert(node->val == 4);

    node1 = root->right->left;
    node2 = root->right->right;
    node = s.lowestCommonAncestor(root, node1, node2);
    assert(node->val == 7);

    node1 = root->right->right;
    node2 = root->right;
    node = s.lowestCommonAncestor(root, node1, node2);
    assert(node->val == 7);


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
    node1 = root->right->right;
    node2 = root->left->left->right;
    node = s.lowestCommonAncestor(root, node1, node2);
    assert(node->val == 10);

    node1 = root->left->left->left;
    node2 = root->left->left->right;
    node = s.lowestCommonAncestor(root, node1, node2);
    assert(node->val == -8);

    node1 = root->left->left->left;
    node2 = root->left->left->right->right;
    node = s.lowestCommonAncestor(root, node1, node2);
    assert(node == NULL);

    node1 = root->left->left->left;
    node2 = root->left->left->left;
    node = s.lowestCommonAncestor(root, node1, node2);
    assert(node->val == 6);

    int tree1[] = {98, 97, -1, 88, -1, 84, -1, -1, 79, 87, 64, -1, -1, -1, 63, 69, 62, -1, -1, -1, 30, -1, 27, 59, 9, -1, -1, -1, 3, -1, 0, -1, -4, -1, -16, -1, -18, -7, -19, -1, -1, -1, -23, -1, -34, -1, -42, -1, -59, -1, -63, -1, -64, -1, -69, -1, -75, -1, -1};
    root = seed_tree(tree1, 59);
    assert(to_str(root) == "98 97 NULL 88 NULL 84 NULL NULL 79 87 64 NULL NULL NULL 63 69 62 NULL NULL NULL 30 NULL 27 59 9 NULL NULL NULL 3 NULL 0 NULL -4 NULL -16 NULL -18 -7 -19 NULL NULL NULL -23 NULL -34 NULL -42 NULL -59 NULL -63 NULL -64 NULL -69 NULL -75 NULL NULL");

    node1 = root->left->left->left
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right;
    node2 = root->left->left->left
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right
        ->right;

    assert(node1->val == -63);
    assert(node2->val == 3);
    node = s.lowestCommonAncestor(root, node1, node2);
    assert(node->val == 3);

    return 0;
}
