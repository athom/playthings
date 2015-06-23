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

//// Independent functions
//class Solution {
//public:

    //int maxPathSumStartWithRoot(TreeNode* root) {
        //if (root == NULL) {
            //return 1 << 31;
        //}
        //int L = maxPathSumStartWithRoot(root->left);
        //int R = maxPathSumStartWithRoot(root->right);

        //if (L < 0 && R < 0) {
            //return root->val;
        //}
        //if (L < 0) {
            //return root->val + R;
        //}
        //if (R < 0) {
            //return root->val + L;
        //}

        //int max = L > R ? L : R;
        //return root->val + max;
    //}

    //int max(int a, int b) {
        //return a > b ? a : b;
    //}
    //int max3(int a, int b, int c) {
        //return max(max(a, b), c);
    //}

    //int iMaxPathSum(TreeNode *root) {
        //if (root == NULL) {
            //return 1<<31;
        //}

        //int L = iMaxPathSum(root->left);
        //int R = iMaxPathSum(root->right);
        //int L_Sum = maxPathSumStartWithRoot(root->left);
        //int R_Sum = maxPathSumStartWithRoot(root->right);

        ////cout << root
                ////<< " root->val:" << root->val
                ////<< " Sum:" << Sum
                ////<< " L_Sum:" << L_Sum
                ////<< " R_Sum:" << R_Sum
                ////<< " L:" << L
                ////<< " R:" << R
                ////<< endl;

        //if (L_Sum < 0 && R_Sum < 0) {
            //return max3(L, root->val, R);
        //}

        //if (L_Sum < 0) {
            //return max3(L, R_Sum + (root->val > 0 ? root->val : 0), R);
        //}

        //if (R_Sum < 0) {
            //return max3(L, L_Sum + (root->val > 0 ? root->val : 0), R);
        //}

        //return max3(L, L_Sum + root->val + R_Sum, R);
    //}
    ///**
     //* @param root: The root of binary tree.
     //* @return: An integer
     //*/
    //int maxPathSum(TreeNode *root) {
        //if (root == NULL) {
            //return 0;
        //}
        //return iMaxPathSum(root);
    //}
//};

// Parallel
class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }
    /**
     * @param root: The root of binary tree.
     * @return: An array, first element is singleMaxPathSum;
     *          Second element is the maxPathSum;
     */
    vector<int> iMaxPathSum(TreeNode* root) {
        vector<int> v;
        if (root == NULL) {
            v.push_back(1<<31);
            v.push_back(1<<31);
            return v;
        }

        vector<int> L = iMaxPathSum(root->left);
        vector<int> R = iMaxPathSum(root->right);
        v.push_back(1<<31);
        v.push_back(1<<31);

        if (L[0] < 0  && R[0] < 0) {
            v[0] = root->val;
        } else if (L[0] < 0) {
            v[0] = root->val + R[0];
        } else if (R[0] < 0) {
            v[0] = L[0] + root->val;
        } else {
            v[0] = max(L[0], R[0]) + root->val;
        }

        if (L[1] < 0 && R[1] < 0) {
            v[1] = max3(L[1], v[0], R[1]);
            return v;
        }

        if (L[1] < 0) {
            v[1] = max(v[0], R[1]);
            return v;
        }

        if (R[1] < 0) {
            v[1] = max(L[1], v[0]);
            return v;
        }

        int r = max3(L[1], L[0] + root->val + R[0], R[1]);
        v[1] = max(r, v[0]);
        return v;
    }

    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        vector<int> v = iMaxPathSum(root);
        return v[1];
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


    r = s.maxPathSum(NULL);
    assert(r == 0);

    int tree3[] = {2, 1, -1, -1, -1};
    root = seed_tree(tree3, 5);
    assert(to_str(root) == "2 1 NULL NULL NULL");
    r = s.maxPathSum(root);
    assert(r == 3);

    //     2
    //    / \
    //   1   4
    //      /
    //     3
    int tree4[] = {2, 1, 4, -1, -1, 3, -1, -1, -1};
    root = seed_tree(tree4, 9);
    assert(to_str(root) == "2 1 4 NULL NULL 3 NULL NULL NULL");
    r = s.maxPathSum(root);
    assert(r == 10);

    //          2
    //         / \
    //        1   6
    //            /
    //           4
    int tree5[] = {2, 1, 6, -1, -1, 4, -1, -1, -1};
    root = seed_tree(tree5, 9);
    assert(to_str(root) == "2 1 6 NULL NULL 4 NULL NULL NULL");
    r = s.maxPathSum(root);
    assert(r == 13);

    //           2
    //          / \
    //         1   6
    //        / \
    //       4   5
    int tree6[] = {2, 1, 6, -1, -1, 4, 5, -1, -1, -1, -1};
    root = seed_tree(tree6, 11);
    assert(to_str(root) == "2 1 6 NULL NULL 4 5 NULL NULL NULL NULL");
    r = s.maxPathSum(root);
    assert(r == 15);


    //          10
    //         / \
    //        5   15
    //           / \
    //          6   20
    int tree7[] = {10, 5, 15, -1, -1, 6, 20, -1, -1, -1, -1};
    root = seed_tree(tree7, 11);
    assert(to_str(root) == "10 5 15 NULL NULL 6 20 NULL NULL NULL NULL");
    r = s.maxPathSum(root);
    assert(r == 50);

    //          10
    //         /  \
    //        5    15
    //         \     \
    //         11     20
    int tree8[] = {10, 5, 15, -1, 11, -1, 20, -1, -1, -1, -1};
    root = seed_tree(tree8, 11);
    assert(to_str(root) == "10 5 15 NULL 11 NULL 20 NULL NULL NULL NULL");
    r = s.maxPathSum(root);
    assert(r == 61);

    //          10
    //         /  \
    //        5    15
    //         \     \
    //          9     20
    int tree9[] = {10, 5, 15, -1, 9, -1, 20, -1, -1, -1, -1};
    root = seed_tree(tree9, 11);
    assert(to_str(root) == "10 5 15 NULL 9 NULL 20 NULL NULL NULL NULL");
    r = s.maxPathSum(root);
    assert(r == 59);

    //          10
    //         /  \
    //        5    -15
    //         \     \
    //          9     20
    int tree10[] = {10, 5, -15, -1, 9, -1, 20, -1, -1, -1, -1};
    root = seed_tree(tree10, 11);
    assert(to_str(root) == "10 5 -15 NULL 9 NULL 20 NULL NULL NULL NULL");
    r = s.maxPathSum(root);
    assert(r == 29);

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
    r = s.maxPathSum(root);
    assert(r == 29);

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
    r = s.maxPathSum(root);
    assert(r == -5);

    // {-191,563,664,-875,988,198,-505,-420,795,957,#,536,-995,-681,821,381,-852,-506,-786,964,392,-675,-654,-717,479,-402,-223,-666,#,249,#,#,#,714,164,#,#,#,#,-580,#,#,652,-153,144,142,-776,906,-665,194,#,#,#,#,#,382,#,25,118,#,433,-754,53,701,#,-496,837,#,#,994,-440,#,-98,-456,852,-237,-159,#,92,628,-681,#,#,547,#,#,600,#,#,#,#,#,#,#,#,#,#,237,-127,795,#,#,#,316,53,-191,628,3,357,474,#,#,#,#,#,#,#,#,#,-746,-650,#,805,-201,750,#,#,#,#,-925,-237,#,-147,629,-769,#,#,#,-846,#,-776,#,#,#,#,#,#,#,#,#,#,-906,552,#,#,#,#,675,-832,594,#,-61,#,#,#,-291,-783,#,#,-660,#,789,#,#,-786,-853,#,-534,-321,-564,-398,358,-874,#,#,#,#,#,#,#,#,#,#,#,#,#,-598,#,#,#,#,#,593}

    return 0;
}
