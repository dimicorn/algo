#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> seen;
        int l = 0;
        int r = 0;
        int res = 0;
        while (l <= r && r < s.length()) {
            if (seen.size() < 2) {
                if (seen.find(s[r]) == seen.end()) {
                    seen[s[r]] = 1;
                } else {
                    ++seen[s[r]];
                }
            } else if (seen.find(s[r]) == seen.end()) {
                while (seen.size() == 2 && l <= r) {
                    --seen[s[l]];
                    if (seen[s[l]] == 0) {
                        seen.erase(s[l]);
                    }
                    ++l;
                }
                seen[s[r]] = 1;
            } else {
                ++seen[s[r]];
            }
            res = max(res, r - l + 1);
            ++r;
        }
        return res;
    }
};
