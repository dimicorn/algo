#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans = {};
		if (s.length() < p.length()) {
			return ans;
		}
		vector<int> freq(26, 0), window(26, 0);
		for (auto &i : p) {
			freq[i-'a']++;
		}
		for (int i = 0; i < p.length(); ++i) {
			window[s[i]-'a']++;
		}
		if (window == freq) {
			ans.push_back(0);
		}
		for (int i = p.length(); i < s.length(); ++i) {
			window[s[i-p.length()]-'a']--;
			window[s[i]-'a']++;
			if (window == freq) {
				ans.push_back(i - p.length() + 1);
			}
		}
		return ans;
	}
};

void print(vector<int>& v) {
	for (auto &i : v) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
	string s = "cbaebabacd";
	string p = "abc";
	Solution sol;
	vector<int> ans = sol.findAnagrams(s, p);
	print(ans);

	s = "abab";
	p = "ab";
	ans = sol.findAnagrams(s, p);
	print(ans);

	return 0;
}
