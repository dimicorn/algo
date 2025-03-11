#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum = (n * n) * (n * n + 1) / 2;
        set<int> s;
        int rep;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s.find(grid[i][j]) == s.end()) {
                    s.insert(grid[i][j]);
                    sum -= grid[i][j];
                } else {
                    rep = grid[i][j];
                }
            }
        }
        return {rep, sum};
    }
};
