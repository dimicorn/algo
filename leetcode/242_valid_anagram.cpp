#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) {
			return false;
		}
		int n = s.length();
		int* buf = new int[26];
		int* ruf = new int[26];
		for (int i = 0; i < n; ++i) {
			buf[s[i]-'a']++;
			ruf[t[i]-'a']++;
		}
		for (int i = 0; i < 26; ++i) {
			if (buf[i] != ruf[i]) {
				return false;
			}
		}
		delete [] buf;
		delete [] ruf;
		return true;
	}
};

int main() {
	Solution sol;
	string s1 = "anagram";
	string t1 = "nagaram";
	string s2 = "rat";
	string t2 = "car";

	if (sol.isAnagram(s1, t1)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	if (sol.isAnagram(s2, t2)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	return 0;
}
