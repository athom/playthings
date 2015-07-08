//#include<>
#include<iostream>
#include<sstream>
#include<stack>
#include <vector>
#include <set>
#include <assert.h>
#include <utility>

using namespace std;

class Solution {
public:
    bool checkSmallSquare(const vector<vector<char> >& b, int x, int y) {
        set<char> s;
        for (int i = x; i < x+3; ++i) {
            for (int j = y; j < y+3; ++j) {
                char c = b[i][j];
                if (c == '.') {
                    continue;
                }
                if (s.find(c) != s.end()) {
                    return false;
                }
                s.insert(c);
            }
        }
        return true;
    }
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char> >& board) {
        for (int i = 0; i < 9; ++i) {
            set<char> s;
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                if (s.find(c) != s.end()) {
                    return false;
                }
                s.insert(c);
            }
        }

        for (int i = 0; i < 9; ++i) {
            set<char> s;
            for (int j = 0; j < 9; ++j) {
                char c = board[j][i];
                if (c == '.') {
                    continue;
                }
                if (s.find(c) != s.end()) {
                    return false;
                }
                s.insert(c);
            }
        }

        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                if (!checkSmallSquare(board, i, j)) {
                    return false;
                }
            }
        }


        return true;
    }
};

vector<vector<char> > seed_matrix(string a[], int x, int y) {
    vector<vector<char> > m;
    for (int i = 0; i < x; i++) {
        vector<char> v;
        for (int j = 0; j < y; j++) {
            v.push_back(a[i][j]);
        }
        m.push_back(v);
    }
    return m;
}

string matrix_to_str(vector<vector<char> > m) {
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

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<char> >b;
    bool r;

    string a1[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    b = seed_matrix(a1, 9, 9);
    r = s.isValidSudoku(b);
    assert(r == true);

    return 0;
}
