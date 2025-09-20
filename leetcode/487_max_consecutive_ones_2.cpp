#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int count = 1;
        int res = 0;
        while (l <= r && r < nums.size()) {
            if (nums[r] == 0 && count == 1) {
                --count;
            } else if (nums[r] == 0 && count == 0) {
                while (nums[l] != 0) {
                    ++l;
                }
                ++l;
            }
            res = max(res, r - l + 1);
            ++r;
        }
        return res;
    }
};
