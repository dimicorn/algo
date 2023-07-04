#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int j = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ' ') {
				reverse(s.begin()+j, s.begin()+i);
				j = i + 1;
			}
			if (i == s.length() - 1) {
				reverse(s.begin()+j, s.end());
			}
		}
		return s;
	}
};

int main(int argc, char* argv[]) {
	string s = "Let's take LeetCode contest";
	Solution sol;
	string ans = sol.reverseWords(s);
	cout << ans << '\n';

	s = "God Ding";
	ans = sol.reverseWords(s);
	cout << ans << '\n';

	return 0;
}
