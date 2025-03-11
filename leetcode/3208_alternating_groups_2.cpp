#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> buf = colors;
        for (int i = 0; i < k - 1; ++i)
            buf.push_back(colors[i]);

        int count = 0;
        int left = 0;
        int right = 1;
        while (right < buf.size()) {
            if (buf[right] == buf[right-1]) {
                left = right;
                ++right;
            } else {
                ++right;
                if (right - left < k) {
                    continue;
                } else {
                    ++count;
                    ++left;
                }
            }
        }
        return count;
    }
};
