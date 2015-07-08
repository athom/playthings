//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<map>
#include <assert.h>
#include <utility>

using namespace std;

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


//class Solution {
//public:
    //vector<int> adjacent(vector<vector<int> >m,  int x, int y) {
        //vector<int> v;
        //if (x == 0 && y == 0) {
            //return v;
        //}
        //if (x == 0) {
            //if (m[0][y-1] > 0) {
                //v.push_back(m[0][y-1]);
            //}
            //return v;
        //}

        //if (y == 0) {
            //if (m[x-1][0] > 0) {
                //v.push_back(m[x-1][0]);
            //}
            //return v;
        //}

        //if (m[x-1][y] > 0) {
            //v.push_back(m[x-1][y]);
        //}
        //if (m[x][y-1] > 0) {
            //v.push_back(m[x][y-1]);
        //}
        //return v;
    //}

    ///**
     //* @param grid a boolean 2D matrix
     //* @return an integer
     //*/
    //int numIslands(vector<vector<bool> >& grid) {
        //vector<vector<int> > m;
        //int x = grid.size();
        //if (x == 0) {
            //return 0;
        //}
        //int y = grid[0].size();
        //if (y == 0) {
            //return 0;
        //}
        //for (int i = 0; i < x; ++i) {
            //vector<int> v;
            //for (int j = 0; j < y; ++j) {
                //if (grid[i][j]) {
                    //v.push_back(1);
                //} else {
                    //v.push_back(0);
                //}
            //}
            //m.push_back(v);
        //}

        //int count = 0;
        //map<int, vector<pair<int, int> > > hash;
        //for (int i = 0; i < x; ++i) {
            //for (int j = 0; j < y; ++j) {
                //if (m[i][j] == 0) {
                    //continue;
                //}

                //vector<int> v = adjacent(m, i, j);
                //int sz = v.size();
                //if (sz == 0) {
                    //pair<int, int> pos;
                    //pos = make_pair(i, j);
                    //int key = hash.size() + 1;
                    //vector<pair<int, int> >markedIslands;
                    //markedIslands.push_back(pos);
                    //hash[key] = markedIslands;
                    //m[i][j] = key;
                    //continue;
                //}

                //if (sz == 1 || v[0] == v[1]) {
                    //pair<int, int> pos;
                    //pos = make_pair(i, j);
                    //int key = v[0];
                    //hash[key].push_back(pos);
                    //m[i][j] = key;
                    //continue;
                //}

                //int key;
                //int discardKey;
                //if (v[0] < v[1]) {
                    //key = v[0];
                    //discardKey = v[1];
                //} else {
                    //key = v[1];
                    //discardKey = v[0];
                //}

                //pair<int, int> pos;
                //pos = make_pair(i, j);
                //hash[key].push_back(pos);
                //m[i][j] = key;

                //vector<pair<int, int> > otherIsland = hash[discardKey];
                //for (int k = 0; k < otherIsland.size(); ++k) {
                    //pair<int, int> pos = otherIsland[k];
                    //m[pos.first][pos.second] = key;
                    //hash[key].push_back(otherIsland[k]);
                //}
                //hash.erase(discardKey);
            //}
        //}

        //return hash.size();
    //}
//};

class Solution {
public:
    void dfsMark(vector<vector<int> >& m, int x, int y) {
        int xLen = m.size();
        int yLen = m[0].size();
        if (x >= xLen || x < 0) {
            return;
        }
        if (y >= yLen || y < 0) {
            return;
        }
        if (m[x][y] == 0) {
            return;
        }

        m[x][y] = 0;
        dfsMark(m, x+1, y);
        dfsMark(m, x, y+1);
        dfsMark(m, x-1, y);
        dfsMark(m, x, y-1);
    }

    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool> >& grid) {
        vector<vector<int> > m;
        int x = grid.size();
        if (x == 0) {
            return 0;
        }
        int y = grid[0].size();
        if (y == 0) {
            return 0;
        }
        for (int i = 0; i < x; ++i) {
            vector<int> v;
            for (int j = 0; j < y; ++j) {
                if (grid[i][j]) {
                    v.push_back(1);
                } else {
                    v.push_back(0);
                }
            }
            m.push_back(v);
        }


        int count = 0;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (m[i][j] == 0) {
                    continue;
                }
                count++;
                dfsMark(m, i, j);
            }
        }

        return count;
    }
};

string matrix_to_str(vector<vector<bool> > m) {
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

vector<vector<bool> > seed_matrix(int* a, int x, int y) {
    vector<vector<bool> > m;
    for (int i = 0; i < x; i++) {
        vector<bool> v;
        for (int j = 0; j < y; j++) {
            v.push_back(*(a+y*i + j));
        }
        m.push_back(v);
    }
    return m;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<bool> > m;
    int r;

    int a1[2][2] = {
        {1, 0},
        {0, 1}
    };
    m = seed_matrix(*a1, 2, 2);
    assert(matrix_to_str(m) == "1 0\n0 1\n");
    r = s.numIslands(m);
    assert(r == 2);

    int a2[5][5] = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1}
    };
    m = seed_matrix(*a2, 5, 5);
    assert(matrix_to_str(m) == "1 1 0 0 0\n0 1 0 0 1\n0 0 0 1 1\n0 0 0 0 0\n0 0 0 0 1\n");
    r = s.numIslands(m);
    assert(r == 3);


    int a3[][6] = {
        {1,1,1,1,1,1},
        {1,0,0,0,0,1},
        {1,0,1,1,0,1},
        {1,0,0,0,0,1},
        {1,1,1,1,1,1}
    };

    m = seed_matrix(*a3, 5, 6);
    assert(matrix_to_str(m) == "1 1 1 1 1 1\n1 0 0 0 0 1\n1 0 1 1 0 1\n1 0 0 0 0 1\n1 1 1 1 1 1\n");
    r = s.numIslands(m);
    assert(r == 2);

    int a4[][20] = {
        {1,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,1,1,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0},
        {0,0,0,1,1,1,1,0,1,0,1,1,0,0,0,0,1,0,1,0},
        {0,0,0,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1},
        {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,1,0,1},
        {0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
        {0,0,0,1,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0},
        {0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,1,0,1},
        {0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0},
        {1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0},
        {0,1,0,0,0,1,0,1,0,1,1,0,1,1,1,0,1,1,0,0},
        {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
        {0,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,0,0,0},
        {0,0,1,1,1,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0},
        {1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,1},
        {1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0},
        {0,1,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,1,0,0},
        {0,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1},
        {0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,0}
    };
    m = seed_matrix(*a4, 20, 20);
    r = s.numIslands(m);
    assert(r == 58);

    return 0;
}
