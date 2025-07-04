#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    vector nums = {1, 2, 3, 4, 5, 6, 7};
    auto sol = new Solution();
    sol->rotate(nums, 3);
    for (const auto& num : nums)
        cout << num << ' ';
    cout << '\n';

    return 0;
}
