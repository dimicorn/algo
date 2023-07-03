#include <bits/stdc++.h>

using namespace std;

vector<int> inter(vector<int>& v1, vector<int> v2) {
	unordered_map<int, int> m;
	vector<int> ans;
	for (auto &it : v1) {
		if (m.find(it) != m.end()) {
			m[it]++;
		} else {
			m[it] = 1;
		}
	}
	for (auto &it : v2) {
		if (m.find(it) != m.end()) {
			m[it]--;
			ans.push_back(it);
			if (m[it] == 0) {
				m.erase(it);
			}
		}
	}
	return ans;
}

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() < nums2.size()) {
			return inter(nums1, nums2);
		} else {
			return inter(nums2, nums1);
		}
	}
};

void print(vector<int>& v) {
	for (auto &it : v) {
		cout << it << ' ';
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	
	Solution sol;
	vector<int> ans = sol.intersect(nums1, nums2);
	print(nums1);
	print(nums2);
	print(ans);
	
	nums1 = {4, 9, 5};
	nums2 = {9, 4, 9, 8, 4};
	ans = sol.intersect(nums1, nums2);
	print(nums1);
	print(nums2);
	print(ans);
	return 0;
}
