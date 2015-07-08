//#include<>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<map>
#include <algorithm>
#include <assert.h>
#include <utility>

using namespace std;

/**
 * Definition of Interval:
 */
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

string to_str(vector<Interval> v) {
    ostringstream os;

    for(int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
            os << "[" << v[i].start << ", " << v[i].end << "]" << "";
            continue;
        }
        os << "[" << v[i].start << ", " << v[i].end << "]" << " ";
    }
    return os.str();
}

struct Less {
    bool operator()(Interval a, Interval b) {
        return a.start < b.start;
    }
};

class Solution {
public:
    bool isOverlap(Interval i1, Interval i2){
        return ((i1.end >= i2.start) && (i1.start <= i2.end));
    }

    Interval mergeInterval(Interval i1, Interval i2){
        int start = min(i1.start, i2.start);
        int end = max(i1.end, i2.end);
        Interval it(start, end);
        return it;
    }
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> A = intervals;
        int sz = A.size();
        if (sz == 0 || sz == 1) {
            return A;
        }

        Less less;
        sort(A.begin(), A.end(), less);

        vector<Interval> B;
        for (int i = 0; i < sz; ++i) {
            if (i == 0) {
                B.push_back(A[i]);
                continue;
            }

            if (isOverlap(B.back(), A[i])) {
                B[B.size() - 1] = mergeInterval(B.back(), A[i]);
                continue;
            }

            B.push_back(A[i]);
        }

        return B;
    }
};

vector<Interval> seed_intervals(int a[][2], int len) {
    vector<Interval> v;
    for (int i = 0; i < len; i++) {
        Interval it(a[i][0], a[i][1]);
        v.push_back(it);
    }
    return v;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<Interval> v;
    vector<Interval> r;

    int a1[][2] = {
        {1, 2},
        {5, 9}
    };
    v = seed_intervals(a1, 2);
    assert(to_str(v) == "[1, 2] [5, 9]");
    r = s.merge(v);
    assert(to_str(r) == "[1, 2] [5, 9]");

    int a2[][2] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };
    v = seed_intervals(a2, 4);
    assert(to_str(v) == "[1, 3] [2, 6] [8, 10] [15, 18]");
    r = s.merge(v);
    assert(to_str(r) == "[1, 6] [8, 10] [15, 18]");
    return 0;
}
