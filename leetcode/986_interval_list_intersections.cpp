#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        int f = 0, s = 0;
        vector<vector<int>> res;
        while (f < n && s < m) {
            int a = firstList[f][0], b = firstList[f][1];
            int c = secondList[s][0], d = secondList[s][1];
            if (a <= d && c <= b) {
                vector<int> temp = {max(a, c), min(b, d)};
                res.push_back(temp);
            }
            if (b < d) {
                ++f;
            } else if (d < b) {
                ++s;
            } else {
                ++f;
                ++s;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> firstList = {{10,12},{18,19}};
    vector<vector<int>> secondList = {{1,6},{8,11},{13,17},{19,20}};
    Solution* sol = new Solution();
    vector<vector<int>> res = sol->intervalIntersection(firstList, secondList);

    for (auto const &interval : res) {
        cout << '[' << interval[0] << ", " << interval[1] << "] ";
    }
    cout << '\n';

    return 0;
}
