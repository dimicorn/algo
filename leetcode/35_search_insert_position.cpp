#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m  = (l + r) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};

int main() {
    vector nums = {1,3,5,6};
    int target = 7;
    auto sol = new Solution();
    cout << sol->searchInsert(nums, target);
    return 0;
}
