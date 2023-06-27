#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int first_zero = -1;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (first_zero == -1) {
                    first_zero = i;
                }
                count++;
            } else if (first_zero != -1) {
                swap(nums[first_zero+count], nums[first_zero]);
                first_zero++;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> in1 = {0, 1, 0, 3, 12};
    vector<int> in2 = {0};

    Solution sol;

    for (auto& i : in1) {
        cout << i << ' ';
    }
    cout << '\n';
    sol.moveZeroes(in1);
    for (auto& i : in1) {
        cout << i << ' ';
    }
    cout <<"\n\n";
    for (auto& i : in2) {
        cout << i << ' ';
    }
    cout << '\n';
    sol.moveZeroes(in2);
    for (auto& i : in2) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}