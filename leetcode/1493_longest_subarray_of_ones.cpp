#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count_zeros = 0;
        int count_ones1 = 0, count_ones2 = 0;
        int ones = 0;

        for (auto const &num : nums) {
            if (num == 0 && count_zeros == 0) {
                ++count_zeros;
            } else if (num == 1 && count_zeros == 0) {
                ++count_ones1;
            } else if (num == 1 && count_zeros == 1) {
                ++count_ones2;
            } else if (num == 0 && count_zeros == 1) {
                ones = max(ones, count_ones1 + count_ones2);
                count_ones1 = count_ones2;
                count_ones2 = 0;
            } else {
                cout << "wtf\n";
            }
        }
        ones = max(ones, count_ones1 + count_ones2);
        if (count_zeros == 0) --ones;
        return ones;
    }
};

int main() {
    vector<int> nums = {1,1,1};
    Solution* sol = new Solution();
    cout << sol->longestSubarray(nums) << '\n';

    return 0;
}
