#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (auto &it : nums) {
			if (s.find(it) != s.end()) {
				return true;
			} else {
				s.insert(it);
			}
		}
		return false;
	}
};

int main() {
	Solution sol;
	vector<int> nums = {1,2,3,1};
	if (sol.containsDuplicate(nums)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	nums = {1,2,3,4};
	if (sol.containsDuplicate(nums)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	nums = {1,1,1,3,3,4,3,2,4,2};
	if (sol.containsDuplicate(nums)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	return 0;
}
