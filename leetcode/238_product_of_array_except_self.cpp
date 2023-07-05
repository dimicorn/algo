#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int product = 1;
		int count = 0;
		for (auto &i : nums) {
			if (i != 0) {
				product *= i;
			} else {
				count++;
			}
		}
		if (count == 0) {
			for (int i = 0; i < nums.size(); ++i) {
				nums[i] = product / nums[i];
			}
		} else if (count == 1) {
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] == 0) {
					nums[i] = product;
				} else {
					nums[i] = 0;
				}
			}
		} else {
			for (int i = 0; i < nums.size(); ++i) {
				nums[i] = 0;
			}
		}
		return nums;
	}
};

void print(vector<int>& v) {
	for (auto &it : v) {
		cout << it << ' ';
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
	vector<int> nums = {1,2,3,4};
	Solution sol;
	print(nums);
	vector<int> ans = sol.productExceptSelf(nums);
	print(ans);

	nums = {-1,1,0,-3,3};
	print(nums);
	ans = sol.productExceptSelf(nums);
	print(ans);

	return 0;
}
