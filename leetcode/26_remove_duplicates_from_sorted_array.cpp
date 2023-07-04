#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int l = 1;
		int count = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i-1] != nums[i]) {
				nums[l] = nums[i];
				++count;
				++l;
			}
		}
		return count;
	}
};

int main(int argc, char* argv[]) {
	vector<int> nums = {1, 1, 2};
	Solution sol;
	int ans = sol.removeDuplicates(nums);
	cout << ans << '\n';
	for (int i = 0; i < ans; ++i) {
		cout << nums[i] << ' ';
	}
	cout << '\n';

	nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	ans = sol.removeDuplicates(nums);
	cout << ans << '\n';
	for (int i = 0; i < ans; ++i) {
		cout << nums[i] << ' ';
	}
	cout << '\n';
	
	return 0;
}
