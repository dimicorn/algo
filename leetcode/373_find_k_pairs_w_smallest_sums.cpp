#include <bits/stdc++.h>

using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> tmp = {{nums1[0] + nums2[0], 0, 0}};
        vector<vector<int>> res;
        unordered_set<pair<int, int>, pair_hash> seen;
        seen.insert(make_pair(0, 0));
        auto comp = [](const auto& a, const auto& b) {
            return a[0] > b[0];
        };
        while (k > 0 && tmp.size() > 0) {
            make_heap(tmp.begin(), tmp.end(), comp);
            pop_heap(tmp.begin(), tmp.end(), comp);
            auto best = tmp.back();
            int i = best[1];
            int j = best[2];
            tmp.pop_back();
            res.push_back({nums1[i], nums2[j]});
            if (i + 1 < nums1.size() &&
                seen.find(make_pair(i + 1, j)) == seen.end()) {
                tmp.push_back({nums1[i+1] + nums2[j], i+1, j});
                seen.insert(make_pair(i + 1, j));
            }

            if (j + 1 < nums2.size() &&
                seen.find(make_pair(i, j+1)) == seen.end()) {
                tmp.push_back({nums1[i] + nums2[j+1], i, j+1});
                seen.insert(make_pair(i, j + 1));
            }
            --k;
        }
        return res;
    }
};
