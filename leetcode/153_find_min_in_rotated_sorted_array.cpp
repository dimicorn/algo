#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		int l = 0;
		int r = nums.size()-1;
		int m;
		while (l <= r) {
			m = (r + l) / 2;
			if (m != 0 && nums[m] < nums[m-1]) {
				return nums[m];
			}
			if (m != nums.size()-1 && nums[m] > nums[m+1]) {
				return nums[m+1];
			}
			if (nums[m] < nums[r]) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return nums[m];
	}
};

int main(int argc, char* argv[]) {
	vector<int> nums = {3,4,5,1,2};
	Solution sol;
	cout << sol.findMin(nums) << '\n';

	nums = {4,5,6,7,0,1,2};
	cout << sol.findMin(nums) << '\n';

	nums = {11,13,15,17};
	cout << sol.findMin(nums) << '\n';

	return 0;
}
