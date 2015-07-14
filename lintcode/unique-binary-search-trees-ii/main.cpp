//#include<>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
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

string to_str(vector<vector<int> > m) {
    ostringstream os;

    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                os << m[i][j] << " " << endl;
                continue;
            }
            os << m[i][j] << " ";
        }
    }
    return os.str();
}

string to_str(vector<int> s){
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

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }

    vector<TreeNode *> generateTreesHelper(int start, int end) {
        vector<TreeNode*> v;
        if (start > end) {
            v.push_back(NULL);
            return v;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode* > left = generateTreesHelper(start, i-1);
            vector<TreeNode* > right = generateTreesHelper(i+1, end);

            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    v.push_back(root);
                }
            }
        }

        return v;
    }

};

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
    vector<TreeNode*> r;

    r = s.generateTrees(0);
    assert(r.size() == 1);
    assert(to_str(r[0]) == "NULL");

    r = s.generateTrees(1);
    assert(r.size() == 1);
    assert(to_str(r[0]) == "1 NULL NULL");

    r = s.generateTrees(2);
    assert(r.size() == 2);
    assert(to_str(r[0]) == "1 NULL 2 NULL NULL");
    assert(to_str(r[1]) == "2 1 NULL NULL NULL");
    return 0;
}
