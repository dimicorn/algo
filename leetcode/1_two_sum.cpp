#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<pair<int, int>> buf;
		for (int i = 0; i < nums.size(); ++i) {
			buf.push_back(make_pair(nums[i], i));
		}

		sort(buf.begin(), buf.end(), [](auto const &x, auto const &y){return x.first < y.first;});
		int l = 0;
		int r = nums.size() - 1;
		vector<int> ans;
		while (l < r) {
			if (buf[l].first + buf[r].first == target) {
				ans.push_back(buf[l].second);
				ans.push_back(buf[r].second);
				break;
			} else if (buf[l].first + buf[r].first > target) {
				--r;
			} else {
				++l;
			}
		}
		if (ans[0] > ans[1]) {
			swap(ans[0], ans[1]);
		}
		return ans;
	}
};

int main(int argc, char* argv[]) {
	vector<int> in1 = {2, 7, 11, 15};
	int t1 = 9;
	vector<int> in2 = {3, 2, 4};
	int t2 = 6;
	vector<int> in3 = {3, 3};
	int t3 = 6;

	Solution sol;
	cout << sol.twoSum(in1, t1)[0] << ' ' << sol.twoSum(in1, t1)[1] << '\n';
	cout << sol.twoSum(in2, t2)[0] << ' ' << sol.twoSum(in2, t2)[1] << '\n';
	cout << sol.twoSum(in3, t3)[0] << ' ' << sol.twoSum(in3, t3)[1] << '\n';
	return 0;
}
