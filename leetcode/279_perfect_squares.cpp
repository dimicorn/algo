#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n < 4) return n;
        if (n == 4) return 1;
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            for (int j = 2; j * j <= i; ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution* sol = new Solution();
    int n = 12;
    cout << sol->numSquares(n) << '\n';

    return 0;
}
