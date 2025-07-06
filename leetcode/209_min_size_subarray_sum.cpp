#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int cur_sum = nums[0];
        int res = nums.size() + 1;
        while (l <= r && r < nums.size()) {
            if (cur_sum < target) {
                if (r < nums.size() - 1) {
                    ++r;
                    cur_sum += nums[r];
                } else {
                    if (res == nums.size() + 1)
                        return 0;
                    return res;
                }
            } else {
                res = min(res, r - l + 1);
                cur_sum -= nums[l];
                ++l;
            }
        }
        if (res == nums.size() + 1)
            return 0;
        return res;
    }
};

int main() {
    vector nums = {2,3,1,2,4,3};
    auto target = 7;
    auto sol = new Solution();
    cout << sol->minSubArrayLen(target, nums) << '\n';
    return 0;
}
