#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0)
            return vector<vector<int>> {newInterval};
        vector<vector<int>> res;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); ++i) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            int c, d;
            if (!inserted) {
                c = newInterval[0];
                d = newInterval[1];
                if (a <= d && c <= b) {
                    res.push_back({min(a, c), max(b, d)});
                    inserted = true;
                } else {
                    res.push_back(intervals[i]);
                }
            } else {
                c = res[res.size()-1][0];
                d = res[res.size()-1][1];
                if (a <= d && c <= b) {
                    res[res.size()-1][0] = min(a, c);
                    res[res.size()-1][1] = max(b, d);
                } else {
                    res.push_back(intervals[i]);
                }
            }
        }
        if (!inserted) {
            res = {};
            int i;
            for (i = 0; i < intervals.size(); ++i) {
                if (intervals[i][0] < newInterval[0]) {
                    res.push_back(intervals[i]);
                } else {
                    break;
                }
            }
            res.push_back(newInterval);
            while (i < intervals.size()) {
                res.push_back(intervals[i]);
                ++i;
            }

        }
        return res;
    }
};
