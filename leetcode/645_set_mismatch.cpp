#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dupl = -1, mis = -1;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[abs(nums[i]) - 1] < 0)
                dupl = abs(nums[i]);
            else
                nums[abs(nums[i]) - 1] *= -1;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                mis = i + 1;
                break;
            }
        }

        return {dupl, mis};
    }
};


int main() {
    vector<int> nums = {1,2,2,4};
    Solution* sol = new Solution();
    vector<int> res = sol->findErrorNums(nums);
    cout << res[0] << ' ' << res[1] << '\n';

    return 0;
}
