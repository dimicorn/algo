#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		vector<int> ans;
		while (l < r) {
			if (nums[l] + nums[r] == target) {
				ans.push_back(l + 1);
				ans.push_back(r + 1);
				break;
			} else if (nums[l] + nums[r] < target) {
				++l;
			} else {
				--r;
			}
		}
		return ans;
	}
};

int main(int argc, char* argv[]) {
	vector<int> nums = {2, 7, 11, 15};
	int t = 9;
	Solution sol;
	vector<int> ans = sol.twoSum(nums, t);
	cout << ans[0] << ' ' << ans[1] << '\n';

	nums = {2, 3, 4};
	t = 6;
	ans = sol.twoSum(nums, t);
	cout << ans[0] << ' ' << ans[1] << '\n';

	nums = {-1, 0};
	t = -1;
	ans = sol.twoSum(nums, t);
	cout << ans[0] << ' ' << ans[1] << '\n';

	return 0;
}
