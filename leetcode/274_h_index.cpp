#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> buff(1001, 0);
        for (const auto& cite : citations)
            ++buff[cite];
        int count = 0;
        for (int i = 1000; i >= 0; --i) {
            count += buff[i];
            if (i <= count)
                return i;
        }
        return 0;
    }
};
