#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s2.length() < s1.length()) {
			return false;
		}
		vector<int> freq(26, 0), window(26, 0);
		for (auto &i : s1) {
			freq[i-'a']++;
		}
		for (int i = 0; i < s1.length(); ++i) {
			window[s2[i]-'a']++;
		}
		if (window == freq) {
			return true;
		}
		for (int i = s1.length(); i < s2.length(); ++i) {
			window[s2[i-s1.length()]-'a']--;
			window[s2[i]-'a']++;
			if (window == freq) {
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char* argv[]) {
	string s1 = "ab";
	string s2 = "eidbaooo";
	Solution sol;
	if (sol.checkInclusion(s1, s2)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}
	
	s1 = "ab";
	s2 = "eidboaoo";
	if (sol.checkInclusion(s1, s2)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	return 0;
}
