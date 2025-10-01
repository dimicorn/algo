#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int last_index = static_cast<int>(nums.size() - 1);
        int left = 0;
        int right = last_index;
        if (last_index == 0) {
            return 0;
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else if (mid == last_index) {
                if (nums[mid] > nums[mid - 1]) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            } else {
                if (nums[mid] > nums[mid - 1] &&
                    nums[mid] > nums[mid + 1]) {
                    return mid;
                } else if (nums[mid] > nums[mid - 1] &&
                           nums[mid] < nums[mid + 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return left;
    }
};
