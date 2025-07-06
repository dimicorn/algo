#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int l = i + 1;
            int r = n - 1;
            int target = -nums[i];
            while (l < r) {
                if (nums[l] + nums[r] < target) {
                    ++l;
                } else if (nums[l] + nums[r] > target) {
                    --r;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    while (nums[l] == nums[l-1] && l < r)
                        ++l;
                }
            }
        }
        return res;
    }
};

int main() {
    vector nums = {-1,0,1,2,-1,-4};
    auto sol = new Solution();
    auto res = sol->threeSum(nums);
    for (const auto& i : res)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    return 0;
}
