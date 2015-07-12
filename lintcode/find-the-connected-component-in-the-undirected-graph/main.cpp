//#include<>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <assert.h>
#include <utility>

using namespace std;

/**
 * Definition for Undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

string matrix_to_str(vector<vector<int> > m) {
    ostringstream os;
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            if (j == m[i].size() - 1) {
                os << m[i][j] << endl;
                continue;
            }
            os << m[i][j] << " ";
        }
    }
    return os.str();
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

vector<UndirectedGraphNode*> seed_graph(int* a, int x, int y) {
    vector<UndirectedGraphNode*> g;
    map<int, UndirectedGraphNode*> m;

    for (int i = 0; i < x; i++) {
        int value = *(a+y*i);
        UndirectedGraphNode* head;
        if (m.find(value) != m.end()) {
            head = m.at(value);
        } else {
            head = new UndirectedGraphNode(value);
        }

        for (int j = 1; j < y; j++) {
            int value = *(a+y*i+j);
            if (value == -1) {
                break;
            }
            UndirectedGraphNode* node;
            if (m.find(value) != m.end()) {
                node = m.at(value);
            } else {
                node = new UndirectedGraphNode(value);
            }
            head->neighbors.push_back(node);
        }

        //cout << to_str(g) << endl;
        g.push_back(head);
    }

    return g;
}

string to_str(vector<UndirectedGraphNode*> m) {
    ostringstream os;

    for(int i = 0; i < m.size(); i++) {
        vector<UndirectedGraphNode*> v = m[i]->neighbors;
        os << m[i]->label << " ";
        for(int j = 0; j < v.size(); j++) {
            if (j == v.size() - 1) {
                os << v[j]->label << endl;
                continue;
            }
            os << v[j]->label << " ";
        }
    }
    return os.str();
}


class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int> > connectedSet(vector<UndirectedGraphNode*>& nodes) {
        vector<vector<int> > m;
        int sz = nodes.size();
        if (sz == 0) {
            return m;
        }

        map<int, bool> visited;
        queue<UndirectedGraphNode*> q;
        for (int k = 0; k < nodes.size(); ++k) {
            UndirectedGraphNode* head = nodes[k];
            if (visited.find(head->label) == visited.end()) {
                q.push(head);
                visited[head->label] = true;
                vector<int> v;
                while (!q.empty()) {
                    UndirectedGraphNode* node = q.front();
                    for (int i = 0; i < node->neighbors.size(); ++i) {
                        UndirectedGraphNode* newNode = node->neighbors[i];
                        int label = newNode->label;
                        if (visited.find(label) == visited.end()) {
                            q.push(newNode);
                            visited[label] = true;
                        }
                    }
                    v.push_back(node->label);
                    q.pop();
                }
                sort(v.begin(), v.end());
                m.push_back(v);
            }
        }

        return m;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<UndirectedGraphNode*> g;

    int a4[][3] = {
        {1, 2, 4},
        {2, 1, 4},
        {3, 5, -1},
        {4, 1, 2},
        {5, 3, -1}
    };
    g = seed_graph(*a4, 5, 3);
    cout << to_str(g) << endl;
    vector<vector<int> >m;
    m = s.connectedSet(g);
    cout << matrix_to_str(m) << endl;
    return 0;
}
