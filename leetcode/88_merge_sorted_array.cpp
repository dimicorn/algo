#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int l = m - 1;
		int r = n - 1;
		int k = n + m - 1;
		while (k >= 0) {
			if (l >= 0 && r >= 0) {
				if (nums2[r] > nums1[l]) {
					nums1[k] = nums2[r];
					--k;
					--r;
				} else {
					nums1[k] = nums1[l];
					--k;
					--l;
				}
			} else if (r >= 0) {
				nums1[k] = nums2[r];
				--k;
				--r;
			} else {
				break;
			}
		}
	}
};

void print(vector<int>& v) {
	for (auto &i : v) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
	// example 1: nums1 = [1, 2, 3, 0, 0, 0], m = 3
	// nums2 = [2, 5, 6], n = 3
	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	int m = 3;
	vector<int> nums2 = {2, 5, 6};
	int n = 3;
	
	Solution sol;
	sol.merge(nums1, m, nums2, n);
	print(nums1);

	nums1 = {1};
	m = 1;
	nums2 = {};
	n = 0;
	sol.merge(nums1, m, nums2, n);
	print(nums1);

	nums1 = {0};
	m = 0;
	nums2 = {1};
	n = 1;
	sol.merge(nums1, m, nums2, n);
	print(nums1);

	return 0;
}

