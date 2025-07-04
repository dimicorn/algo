#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = nums[0];
        int current_sum = 0;
        for (const auto& x: nums) {
            current_sum = max(x, current_sum + x);
            best_sum = max(best_sum, current_sum);
        }
        return best_sum;
    }
};

int main() {
    vector nums = {-2,1,-3,4,-1,2,1,-5,4};
    auto sol = new Solution();
    cout << sol->maxSubArray(nums) << '\n';

    return 0;
}
