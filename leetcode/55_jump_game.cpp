#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        int cur = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (cur - i <= nums[i]) {
                dp[i] = 1;
                cur = i;
            }
        }
        return dp[0];
    }
};
