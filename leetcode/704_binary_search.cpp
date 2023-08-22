#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size()-1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (nums[m] == target) {
				return m;
			} else if (nums[m] > target) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return -1;
	}
};

int main() {
	Solution sol;
	vector<int> nums = {-1,0,3,5,9,12};
	int target = 9;
	cout << sol.search(nums, target) << '\n';

	target = 2;
	cout << sol.search(nums, target) << '\n';

	return 0;
}
