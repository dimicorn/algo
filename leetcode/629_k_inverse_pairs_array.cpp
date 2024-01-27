#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long mod = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<long long>> dp (n+1, vector<long long>(k+1, 0));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (j >= i)
                    dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i] + mod) % mod;
                else
                    dp[i][j] = (dp[i][j-1] + dp[i-1][j] + mod) % mod;
            }
        }
        return dp[n][k];
    }
};

int main() {
    int n = 3, k = 1;
    Solution* sol = new Solution();
    cout << sol->kInversePairs(n, k) << '\n';

    return 0;
}
