#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        for (int i = 0; i < points.size(); ++i) {
            auto p1 = points[i];
            unordered_map<double, int> m;
            double slope;
            for (int j = i+1; j < points.size(); ++j) {
                auto p2 = points[j];
                slope = (p2[0] == p1[0]) ?
                    numeric_limits<double>::infinity() :
                    static_cast<double>(p2[1] - p1[1]) / static_cast<double>(p2[0] - p1[0]);
                m[slope]++;
                res = max(res, m[slope]+1);
            }
        }
        return res;
    }
};
