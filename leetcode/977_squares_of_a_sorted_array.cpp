#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int l = 0;
		int r = nums.size()-1;
		int i = r;
		vector<int> ans(r+1);
		while (l <= r) {
			if (abs(nums[l]) > abs(nums[r])) {
				ans[i] = nums[l] * nums[l];
				++l;
			} else {
				ans[i] = nums[r] * nums[r];
				--r;
			}
			--i;
		}
		return ans;
	}
};

void print(vector<int>& v) {
	for (auto &it : v) {
		cout << it << ' ';
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
	vector<int> nums = {-4, -1, 0, 3, 10};
	Solution sol;
	vector<int> ans = sol.sortedSquares(nums);
	print(nums);
	print(ans);

	nums = {-7, -3, 2, 3, 11};
	ans = sol.sortedSquares(nums);
	print(nums);
	print(ans);

	return 0;
}
