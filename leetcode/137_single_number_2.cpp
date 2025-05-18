#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for (const auto& num : nums) {
            twos |= ones & num;
            ones ^= num;

            auto common_mask = ~(ones & twos);
            ones &= common_mask;
            twos &= common_mask;
        }
        return ones;
    }
};

int main() {
    vector<int> nums = {2, 2, 3, 2};
    auto sol = new Solution();
    cout << sol->singleNumber(nums) << '\n';
    return 0;
}
