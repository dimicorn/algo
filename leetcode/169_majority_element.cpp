#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m;
        int c = 0;
        for (const auto& num: nums) {
            if (c == 0) {
                m = num;
                c = 1;
            } else if (m == num) {
                ++c;
            } else {
                --c;
            }
        }
        return m;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    auto sol = new Solution();
    cout << sol->majorityElement(nums) << '\n';

    return 0;
}
