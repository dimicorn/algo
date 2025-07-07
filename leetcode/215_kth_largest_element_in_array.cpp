#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int res;
        for (int i = 0; i < k; ++i) {
            pop_heap(nums.begin(), nums.end());
            res = nums.back();
            nums.pop_back();
        }
        return res;
    }
};
