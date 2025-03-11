#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        vector<bool> buf;
        for (const auto& block : blocks) {
            if (block == 'W') {
                buf.push_back(false);
            } else {
                buf.push_back(true);
            }
        }
        int count = 0;
        for (int i = 0; i < k; ++i) {
            if (!buf[i])
                ++count;
        }
        if (count == 0)
            return count;
        cout << count << '\n';
        int res = count;
        for (int i = k; i < buf.size(); ++i) {
            count = (!buf[i-k]) ? count-1 : count;
            count = (!buf[i]) ? count+1 : count;
            res = min(res, count);
            cout << i-k << ' ' << res << '\n';
        }
        return res;
    }
};
