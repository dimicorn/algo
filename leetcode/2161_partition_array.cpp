#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, more, equal;
        for (const auto& it : nums)
            if (it == pivot)
                equal.push_back(it);
            else if (it > pivot)
                more.push_back(it);
            else 
                less.push_back(it);
        vector<int> res;
        res.reserve(nums.size());
        res.insert(res.end(), less.begin(), less.end());
        res.insert(res.end(), equal.begin(), equal.end());
        res.insert(res.end(), more.begin(), more.end());
        return res;
    }
};

int main() {
    auto sol = new Solution();
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    auto res = sol->pivotArray(nums, pivot);
    for (const auto& it : res) 
        cout << it << ' ';
    cout << '\n';
    return 0;
}
