#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();
        int same, j, k;
        for (int i = 0; i < n; ++i) {
            same = 0;
            j = 0;
            k = i;
            while (haystack[k] == needle[j] && k < n && j < m) {
                ++k;
                ++j;
                ++same;
            }
            if (same == m)
                return i;
        }
        return -1;
    }
};
