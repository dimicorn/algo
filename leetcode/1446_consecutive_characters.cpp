#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxPower(string s) {
		int power = 1;
		int temp = 1;
		for (int i = 0; i < s.length() - 1; ++i) {
			if (s[i] == s[i+1]) {
				temp++;
			} else if (temp > power) {
				power = temp;
				temp = 1;
			} else {
				temp = 1;
			}
		}
		if (temp > power) {
			return temp;
		} else {
			return power;
		}
	}
};

int main(int argc, char* argv[]) {
	string s1 = "leetcode";
	string s2 = "abbcccddddeeeeedcba";

	Solution sol;
	cout << s1 << '\n';
	cout << sol.maxPower(s1) << '\n';
	cout << s2 << '\n';
	cout << sol.maxPower(s2) << '\n';
	return 0;
}
