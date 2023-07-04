#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int sum = n * (n + 1) / 2;
		for (int i = 0; i < nums.size(); ++i) {
			sum -= nums[i];
		}
		return sum;
	}
};

int main(int argc, char* argv[]) {
	vector<int> nums = {3, 0, 1};
	Solution sol;
	cout << sol.missingNumber(nums) << '\n';

	nums = {0,1};
	cout << sol.missingNumber(nums) << '\n';

	nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
	cout << sol.missingNumber(nums) << '\n';

	return 0;
}
