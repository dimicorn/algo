#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int l = 0;
		int r = nums.size()-1;
		int m;
		while (l <= r) {
			m = (l + r) / 2;
			if (m != 0 && nums[m-1] > nums[m]) {
				return m;
			}
			if (m != nums.size()-1 && nums[m] > nums[m+1]) {
				return m+1;
			}
			if (nums[m] < nums[r]) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return m;
	}

	int binSearch(vector<int>& nums, int beg, int fin, int t) {
		int l = beg;
		int r = fin;
		int m;
		while (l <= r) {
			m = (l + r) / 2;
			if (nums[m] == t) {
				return m;
			} else if (nums[m] > t) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return -1;
	}

	int search(vector<int>& nums, int target) {
		int pivot = findMin(nums);
		int ans1 = binSearch(nums, 0, pivot-1, target);
		int ans2 = binSearch(nums, pivot, nums.size()-1, target);
		if (ans1 == -1 && ans2 == -1) {
			return -1;
		} else if (ans1 != -1) {
			return ans1;
		} else {
			return ans2;
		}
	}
};

int main(int argc, char* argv[]) {
	vector<int> nums = {4,5,6,7,0,1,2};
	int t = 0;
	Solution sol;
	cout << sol.search(nums, t) << '\n';

	nums = {4,5,6,7,0,1,2};
	t = 3;
	cout << sol.search(nums, t) << '\n';

	nums = {1};
	t = 0;
	cout << sol.search(nums, t) << '\n';

	return 0;
}
