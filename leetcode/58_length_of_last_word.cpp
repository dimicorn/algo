#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while (i >= 0 && !isalpha(s[i]))
            --i;
        int finish = i;
        while (i >= 0 && isalpha(s[i]))
            --i;
        int start = i;
        return finish - start;
    }
};
