#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_set<int> set;
        for (auto const &num : arr) {
            if (map.find(num) != map.end())
                ++map[num];
            else
                map[num] = 1;
        }
        for (auto const &m : map)
            set.insert(m.second);
        return map.size() == set.size();
    }
};

int main() {
    vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
    Solution* sol = new Solution();
    bool res = sol->uniqueOccurrences(arr);
    string ans = (res) ? "true" : "false";
    cout << ans << '\n';

    return 0;
}
