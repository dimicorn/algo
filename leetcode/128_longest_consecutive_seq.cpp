#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (const auto& num : nums)
            s.insert(num);
        int maxLength = 0;
        for (const auto& num : s) {
            if (s.find(num - 1) == s.end()) {
                int start = num;
                while (s.find(start) != s.end())
                    ++start;
                maxLength = max(maxLength, start - num);
            }
        }
        return maxLength;
    }
};
