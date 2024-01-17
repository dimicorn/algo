#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) nums1.swap(nums2);
        int total = nums1.size() + nums2.size();
        int half = total / 2;
        int l = 0, r = nums1.size() - 1;

        while (true) {
            int i = floor((l + r) / 2.0);
            int j = half - i - 2;
            
            long long a_left = (i >= 0) ? nums1[i] : -1e7;
            long long a_right = ((i+1) < nums1.size()) ? nums1[i+1] : 1e7;
            long long b_left = (j >= 0) ? nums2[j] : -1e7;
            long long b_right = ((j+1) < nums2.size()) ? nums2[j+1] : 1e7;

            if (a_left <= b_right && b_left <= a_right) {
                if (total % 2)
                    return min(a_right, b_right);
                else
                    return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
            } else if (a_left > b_right) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
    }
};

int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    Solution* sol = new Solution();
    cout << sol->findMedianSortedArrays(nums1, nums2) << '\n';

    return 0;
}
