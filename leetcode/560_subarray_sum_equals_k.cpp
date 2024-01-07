#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum, count = 0;
        int n = nums.size();
        int pref[n];
        pref[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            pref[i] = nums[i] + pref[i-1];
        }

        unordered_map<int, int> map;

        for (int i = 0; i < n; ++i) {
            if (pref[i] == k) ++count;

            if (map.find(pref[i] - k) != map.end()) {
                count += map[pref[i] - k];
            }
            map[pref[i]]++;
        }
        return count;
    }
};

int main() {
    vector<int> nums = {-1,-1,1};
    int k = 0;
    Solution* sol = new Solution();
    cout << sol->subarraySum(nums, k) << '\n';

    return 0;
}
