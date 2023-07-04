#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i = 0;
		for (int j = 0; j < t.length(); ++j) {
			if (s[i] == t[j]) {
				++i;
			}
		}
		return i == s.length();
	}
};

int main(int argc, char* argv[]) {
	string s = "abc";
	string t = "ahbgdc";
	
	Solution sol;
	if (sol.isSubsequence(s, t)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	s = "axc";
	t = "ahbgdc";
	if (sol.isSubsequence(s, t)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	return 0;
}
