#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> buf(n+1);
        buf[0] = 0;
        for (int i = 1; i <= n; ++i)
            buf[i] = buf[i-1] + nums[i-1];
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 1; i <= n; ++i) {
            if (map.find(buf[i] % k) == map.end()) {
                map[buf[i] % k] = i-1;
            } else if (i - 1 - map[buf[i] % k] >= 2) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {23,2,4,6,7};
    int k = 6;
    Solution* sol = new Solution();
    bool res = sol->checkSubarraySum(nums, k);
    if (res)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
