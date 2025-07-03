#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for (const auto& num : nums) {
            if (m.find(num) == m.end())
                m[num] = 1;
            else
                ++m[num];
        }
        int res = 0;
        for (const auto& i: m) {
            if (m.find(i.first - 1) != m.end()) {
                int minimum = i.first - 1;
                res = max(res, m[minimum] + i.second);
            } else if (m.find(i.first + 1) != m.end()) {
                int maximum = i.first + 1;
                res = max(res, m[maximum] + i.second);
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1,3,2,2,5,2,3,7};
    auto sol = new Solution();
    cout << sol->findLHS(nums) << '\n';
    return 0;
}
