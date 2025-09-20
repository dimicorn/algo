#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        if (abs(s_len - t_len) > 1) {
            return false;
        }
        if (s_len == t_len) {
            // replace
            size_t s_index = 0;
            size_t t_index = 0;
            int count = 0;
            while (s_index < s_len) {
                if (s[s_index] != t[t_index]) {
                    ++count;
                }
                if (count == 2) {
                   return false;
                }
                ++s_index;
                ++t_index;
            }
            return count == 1;
        } else if (s_len > t_len) {
            // inserted char in s
            return checkInsertion(s, t);
        } else {
            // inserted char in t
            return checkInsertion(t, s);
        }
    }
    bool checkInsertion(const string& s, const string& t) {
        size_t s_index = 0;
        size_t t_index = 0;
        int count = 0;
        while (t_index < t.length() && s_index < s.length()) {
            if (s[s_index] != t[t_index]) {
                ++count;
                --t_index;
            }
            if (count == 2) {
                return false;
            }
            ++s_index;
            ++t_index;
        }
        return true;
    }
};
