#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.length(); ++i)
            lastIndex[s[i]] = i;
        vector<int> res;
        int size = 0, end = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++size;
            end = max(end, lastIndex[s[i]]);

            if (i == end) {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};

int main() {
    string s = "ababcbacadefegdehijhklij";
    Solution* sol = new Solution();
    vector<int> ans = sol->partitionLabels(s);
    for (auto const &it : ans)
        cout << it << ' ';
    cout << '\n';

    return 0;
}
