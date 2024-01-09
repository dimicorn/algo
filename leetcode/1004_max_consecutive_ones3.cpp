#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int window[2] = {0, 0};
        int l = 0;
        int count = k;
        int res = 0;
        if (k == 0) {
            count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                count = (nums[i] == 0) ? 0 : count + 1;
                res = max(res, count);
            }
            return res;
        }

        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 1) {
                ++window[1];
            } else if (nums[r] == 0 && count > 0) {
                ++window[0];
                --count;
            } else if (nums[l] == 1) {
                --window[1];
                ++l;
                --r;
            } else if (nums[l] == 0) {
                window[0] = (window[0] == 0) ? 0 : window[0] - 1;
                count = (count == k) ? k : count + 1;
                ++l;
                --r;
            }
            res = max(res, window[0] + window[1]);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,0,0};
    int k = 0;

    Solution* sol = new Solution();
    cout << sol->longestOnes(nums, k) << '\n';

    return 0;
}
