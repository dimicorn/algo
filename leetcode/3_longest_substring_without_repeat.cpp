#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, res = 0;
        unordered_map<char, int> seen;

        for (int r = 0; r < s.length(); ++r) {
            char c = s[r];
            if (seen.find(c) != seen.end() && seen[c] >= l) {
                l = seen[c] + 1;
            } else {
                res = max(res, r - l + 1);
            }
            seen[c] = r;
        }

        return res;
    }
};

int main() {
    string s = "abcabcbb";
    Solution* sol = new Solution();
    cout << sol->lengthOfLongestSubstring(s) << '\n';

    return 0;
}
