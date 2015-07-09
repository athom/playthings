//#include<>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
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
//class Solution {
//public:
    //TreeNode* maxTreeHelper(vector<int> A, int left, int right) {
        //if (right < left) {
            //return NULL;
        //}

        //int INF = ~(1<<31);
        //int maxValue = -INF;
        //int maxIndex = -1;
        //for (int i = left; i <= right; ++i) {
            //if (A[i] > maxValue) {
               //maxValue = A[i];
               //maxIndex = i;
            //}
        //}

        //TreeNode* node = new TreeNode(maxValue);
        //TreeNode* leftTree = maxTreeHelper(A, left, maxIndex-1);
        //TreeNode* rightTree = maxTreeHelper(A, maxIndex+1, right);
        //node->left = leftTree;
        //node->right = rightTree;
        //return node;
    //}
    ///**
     //* @param A: Given an integer array with no duplicates.
     //* @return: The root of max tree.
     //*/
    //TreeNode* maxTree(vector<int> A) {
        //int sz = A.size();
        //if (sz == 0 ) {
            //return 0;
        //}
        //return maxTreeHelper(A, 0, sz-1);
    //}
//};

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        int sz = A.size();
        if (sz == 1) {
            TreeNode* node = new TreeNode(A[0]);
            return node;
        }

        stack<TreeNode*> s;

        TreeNode* cur = NULL;
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = new TreeNode(A[i]);

            if (s.empty()) {
                s.push(node);
                continue;
            }

            cur = NULL;
            while (!s.empty() && s.top()->val < node->val) {
                TreeNode* po = s.top();
                s.pop();
                po->right = cur;
                cur = po;
            }
            if (cur) {
                node->left = cur;
            }

            s.push(node);
        }

        cur = NULL;
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            node->right = cur;
            cur = node;
        }

        return cur;
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

vector<int> seed_array(const int* a, int len) {
    vector<int> v;
    for (int i = 0; i < len; i++) {
        v.push_back(a[i]);
    }
    return v;
}

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v;
    TreeNode* root;
    int r;

    v.clear();
    root = s.maxTree(v);
    assert(to_str(root) == "NULL");

    int a1[] = {2, 5, 6, 0, 3, 1};
    v = seed_array(a1, 6);
    root = s.maxTree(v);
    assert(to_str(root) == "6 5 3 2 NULL 0 1 NULL NULL NULL NULL NULL NULL");

    return 0;
}
