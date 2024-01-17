#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 0; i < n; ++i) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                int low = lower_bound(ans.begin(), ans.end(), nums[i])
                    - ans.begin();
                ans[low] = nums[i];
            }
        }
        return ans.size();
    }
};

int main() {
    vector<int> nums = {4,10,4,3,8,9};
    Solution* sol = new Solution();
    cout << sol->lengthOfLIS(nums) << '\n';

    return 0;
}
