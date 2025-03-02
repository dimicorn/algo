#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int l = 0;
        int r = 0;

        vector<vector<int>> res;
        while (l < n && r < m) {
            int ind1 = nums1[l][0];
            int ind2 = nums2[r][0];
            int val1 = nums1[l][1];
            int val2 = nums2[r][1];

            if (ind1 == ind2) {
                res.push_back({ind1, val1+val2});
                ++l;
                ++r;
            } else if (ind1 < ind2) {
                res.push_back({ind1, val1});
                ++l;
            } else {
                res.push_back({ind2, val2});
                ++r;
            }
        }
        while (l < n) {
            res.push_back(nums1[l]);
            ++l;
        }
        while (r < m) {
            res.push_back(nums2[r]);
            ++r;
        }
                    
        return res;
    }
};

int main() {
    auto sol = new Solution();
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
    auto res = sol->mergeArrays(nums1, nums2);
    for (const auto& it : res)
        cout << it[0] << ", " << it[1] << '\n';
    return 0;
}
