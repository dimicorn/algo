#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res = {words[0]};
        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != groups[i-1])
                res.push_back(words[i]);
        }
        return res;
    }
};

int main() {
    vector<string> words = {"a", "b", "c", "d"};
    vector<int> groups = {1, 0, 1, 1};
    auto sol = new Solution();
    auto res = sol->getLongestSubsequence(words, groups);
    for (const auto& i : res)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
