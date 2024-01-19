#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> tmp(n, 0);
        vector<vector<int>> dp(n, tmp);
        for (int c = 0; c < n; ++c)
            dp[0][c] = matrix[0][c];
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (c == 0) {
                    dp[r][c] = min(dp[r-1][c], dp[r-1][c+1]) + matrix[r][c];
                } else if (c == n - 1) {
                    dp[r][c] = min(dp[r-1][c-1], dp[r-1][c]) + matrix[r][c];
                } else {
                    int tmp = min(dp[r-1][c-1], dp[r-1][c]);
                    dp[r][c] = min(tmp, dp[r-1][c+1]) + matrix[r][c];
                }
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

int main() {
    vector<vector<int>> matrix = {{2,1,3}, {6,5,4}, {7,8,9}};
    Solution* sol = new Solution();
    cout << sol->minFallingPathSum(matrix) << '\n';

    return 0;
}
