#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int total = 0;
        vector<int> freq(3, 0);
        while (right < n) {
            ++freq[s[right]-'a'];
            while (hasAllChars(freq)) {
                total += n - right;
                --freq[s[left]-'a'];
                ++left;
            }
            ++right;
        }
        return total;
    }
    bool hasAllChars(vector<int> freq) {
        for (const auto &i : freq)
            if (i < 1)
                return false;
        return true;
    }
};
