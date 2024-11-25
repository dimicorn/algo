#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        int firstVal = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != val && count == 0) {
                continue;
            } else if (nums[i] != val && count == 1) {
                swap(nums[i], nums[firstVal]);
                firstVal = i;
            } else if (nums[i] != val && count > 1) {
                swap(nums[i], nums[firstVal]);
                ++firstVal;
            } else if (nums[i] == val && count == 0) {
                ++count;
                firstVal = i;
            } else if (nums[i] == val && count > 0) {
                ++count;
            }
            for (const auto &it : nums)
                cout << it << ' ';
            cout << '\n';
        }
        return n - count;
    }
};
