#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1)
            return 1;
        sort(points.begin(), points.end(),
            [](const auto& a, const auto& b) {return a[0] < b[0];});
        vector<vector<int>> res = {points[0]};
        for (int i = 1; i < points.size(); ++i) {
            auto prev = res[res.size() - 1];
            auto cur = points[i];
            int a = prev[0];
            int b = prev[1];
            int c = cur[0];
            int d = cur[1];
            if (a <= d && c <= b) {
                res[res.size() - 1][0] = max(a, c);
                res[res.size() - 1][1] = min(b, d);
            } else {
                res.push_back(cur);
            }
        }
        return res.size();
    }
};
