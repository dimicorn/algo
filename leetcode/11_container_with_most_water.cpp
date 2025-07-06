#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        while (l <= r) {
            res = max(res, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};

int main() {
    vector nums = {1,8,6,2,5,4,8,3,7};
    auto sol = new Solution();
    cout << sol->maxArea(nums) << '\n';
    return 0;
}
