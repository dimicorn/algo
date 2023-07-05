#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> m;
		for (int i = 0; i < s.length(); ++i) {
			if (m.find(s[i]) == m.end()) {
				m[s[i]] = 1;
			} else {
				m[s[i]]++;
			}
		}
		for (int i = 0; i < s.length(); ++i) {
			if (m[s[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};

int main(int argc, char* argv[]) {
	string s = "leetcode";
	Solution sol;
	cout << sol.firstUniqChar(s) << '\n';

	s = "loveleetcode";
	cout << sol.firstUniqChar(s) << '\n';

	s = "aabb";
	cout << sol.firstUniqChar(s) << '\n';

	return 0;
}
