#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res1 = kadaneAlgo(nums);
        int res2 = kadaneAlgoMin(nums);
        return (res1 > 0) ? max(res1, res2) : res1;
    }
    int kadaneAlgo(vector<int>& nums) {
        int best_sum = nums[0];
        int current_sum = 0;
        for (const auto& x : nums) {
            current_sum = max(x, current_sum + x);
            best_sum = max(best_sum, current_sum);
        }
        return best_sum;
    }
    int kadaneAlgoMin(vector<int>& nums) {
        int best_sum = nums[0];
        int current_sum = 0;
        int total_sum = 0;
        for (const auto& x : nums) {
            current_sum = min(x, current_sum + x);
            best_sum = min(best_sum, current_sum);
            total_sum += x;
        }
        return total_sum - best_sum;
    }
};

int main() {
    vector nums = {5, -3, 5};
    auto sol = new Solution();
    cout << sol->maxSubarraySumCircular(nums) << '\n';
    return 0;
}
