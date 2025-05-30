#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            res ^= nums[i];
        return res;
    }
};

int main() {
    vector<int> nums = {-1, -1, -2};
    auto sol = new Solution();
    cout << sol->singleNumber(nums) << '\n';
    return 0;
}
