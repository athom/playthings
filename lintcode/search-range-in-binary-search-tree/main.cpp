//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> v;
        if (root == NULL) {
            return v;
        }

        if (k1 <= root->val && root->val <= k2) {
            v.push_back(root->val);
        }

        vector<int> L = searchRange(root->left, k1, k2);
        vector<int> R = searchRange(root->right, k1, k2);

        if (!L.empty()) {
            v.insert(v.begin(), L.begin(), L.end());
        }
        if (!R.empty()) {
            v.insert(v.end(), R.begin(), R.end());
        }

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

    v = s.searchRange(NULL, 1, 2);
    assert(v.empty());

    int tree1[] = {20, 8, 22, 4, 12, -1, -1, -1, -1, -1, -1};
    root = seed_tree(tree1, 11);
    assert(to_str(root) == "20 8 22 4 12 NULL NULL NULL NULL NULL NULL");
    v = s.searchRange(root, 10, 22);
    assert(to_str_v(v) == "12 20 22 \n");
    v = s.searchRange(root, 10, 25);
    assert(to_str_v(v) == "12 20 22 \n");
    v = s.searchRange(root, 10, 21);
    assert(to_str_v(v) == "12 20 \n");
    v = s.searchRange(root, 10, 12);
    assert(to_str_v(v) == "12 \n");
    v = s.searchRange(root, 12, 13);
    assert(to_str_v(v) == "12 \n");
    v = s.searchRange(root, 1, 23);
    assert(to_str_v(v) == "4 8 12 20 22 \n");


    return 0;
}
