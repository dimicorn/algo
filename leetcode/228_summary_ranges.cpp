#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        pair<int, int> tmp;
        if (nums.size() > 1) {
            for (int i = 1; i < nums.size(); ++i) {
                if (i == 1) {
                    if (nums[i-1] + 1 != nums[i]) {
                        res.push_back(to_string(nums[i-1]));
                        tmp = make_pair(nums[i], nums[i]);
                    } else {
                        tmp = make_pair(nums[i-1], nums[i]);
                    }
                } else if (i == nums.size()-1) {
                    if (nums[i-1] + 1 != nums[i]) {
                        res.push_back(to_string(tmp.first) + "->" + to_string(tmp.second));
                        res.push_back(to_string(nums[i]));
                    } else {
                        tmp.second++;
                        res.push_back(to_string(tmp.first) + "->" + to_string(tmp.second));
                    }
                } else {
                    if (nums[i-1] + 1 != nums[i]) {
                        if (tmp.first == tmp.second) {
                            res.push_back(to_string(tmp.first));
                        } else {
                            res.push_back(to_string(tmp.first) + "->" + to_string(tmp.second));
                        }
                        tmp = make_pair(nums[i], nums[i]);
                    } else {
                        tmp.second++;
                    }
                }
            }
        } else if (nums.size() == 1) {
            res.push_back(to_string(nums[0]));
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<int> in1 = {0, 1, 2, 4, 5, 7};
    vector<int> in2 = {0, 2, 3, 4, 6, 8, 9};

    for (auto& i: in1) {
        cout << i << ' ';
    }
    cout << '\n';
    vector<string> out1 = sol.summaryRanges(in1);
    for (auto& i : out1) {
        cout << i << ' ';
    }
    cout << '\n';
    cout << '\n';

    for (auto& i: in2) {
        cout << i << ' ';
    }
    cout << '\n';
    vector<string> out2 = sol.summaryRanges(in2);
    for (auto& i : out2) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

