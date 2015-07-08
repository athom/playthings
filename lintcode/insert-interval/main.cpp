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
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> v;
        int sz = intervals.size();
        if (sz == 0) {
            v.push_back(newInterval);
            return v;
        }

        bool inserted = false;
        for (int i = 0; i < sz; ++i) {
            if (inserted) {
                v.push_back(intervals[i]);
                continue;
            }

            if (isOverlap(intervals[i], newInterval)) {
                newInterval = mergeInterval(intervals[i], newInterval);
                continue;
            }

            if (newInterval.end < intervals[i].start) {
                v.push_back(newInterval);
                inserted = true;
            }
            v.push_back(intervals[i]);
        }

        if (!inserted) {
            v.push_back(newInterval);
        }

        return v;
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
    Interval it(2,5);
    r = s.insert(v, it);
    assert(to_str(r) == "[1, 9]");

    v = seed_intervals(a1, 2);
    Interval it2(3,4);
    r = s.insert(v, it2);
    assert(to_str(r) == "[1, 2] [3, 4] [5, 9]");

    v = seed_intervals(a1, 2);
    Interval it3(3,4);
    r = s.insert(v, it3);
    assert(to_str(r) == "[1, 2] [3, 4] [5, 9]");


    v = seed_intervals(a1, 2);
    Interval it4(2,4);
    r = s.insert(v, it4);
    assert(to_str(r) == "[1, 4] [5, 9]");


    v = seed_intervals(a1, 2);
    Interval it5(0,4);
    r = s.insert(v, it5);
    assert(to_str(r) == "[0, 4] [5, 9]");


    v = seed_intervals(a1, 2);
    Interval it6(0,10);
    r = s.insert(v, it6);
    assert(to_str(r) == "[0, 10]");
    return 0;
}
