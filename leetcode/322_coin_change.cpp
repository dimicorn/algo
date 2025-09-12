#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int w = 1; w <= amount; ++w) {
            for (const auto& coin : coins) {
                if (w - coin >= 0)
                    dp[w] = min(dp[w], 1 + dp[w - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
