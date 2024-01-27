#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        m_ = m;
        n_ = n;
        dp = vector<vector<vector<int>>> (maxMove+1, vector<vector<int>>(m, vector<int>(n, INT_MIN)));
        return find(maxMove, startColumn, startRow);
    }
private:
    int n_, m_;
    vector<vector<vector<int>>> dp;
    long long MOD = 1e9 + 7;
    int find(int N, int x, int y) {
        if (x < 0 || x >= n_ || y < 0 || y >= m_) return 1;
        if (N == 0) return 0;
        if (dp[N][y][x] != INT_MIN) return dp[N][y][x];

        long long ans = 0;
        ans += find(N-1, x+1, y);
        ans += find(N-1, x-1, y);
        ans += find(N-1, x, y+1);
        ans += find(N-1, x, y-1);
        ans %= MOD;

        return dp[N][y][x] = ans;
    }
};

int main() {
    int m = 2, n = 2, maxMove = 2;
    int startRow = 0, startColumn = 0;
    Solution* sol = new Solution();
    cout << sol->findPaths(m, m, maxMove, startRow, startColumn) << '\n';

    return 0;
}
