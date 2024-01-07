#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        if (s.length() == 1)
            return s;

        string res = "";
        for (int i = 0; i < s.length(); ++i) {
            string sub1 = expand(s, i, i);
            if (sub1.length() > res.length())
                res = sub1;

            string sub2 = expand(s, i, i+1);
            if (sub2.length() > res.length())
                res = sub2;
        }
        return res;
    }
    string expand(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return s.substr(l+1, r - l - 1);
    }
};

int main() {
    string s = "cbbd";
    Solution* sol = new Solution();
    cout << sol->longestPalindrome(s) << '\n';
    
    return 0;
}
