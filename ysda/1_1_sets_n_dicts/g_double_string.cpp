#include <bits/stdc++.h>

using namespace std;

string solve(int n, string* s, map<string, bool> m) {
	string ans = "";
	for (int i = 0; i < n; ++i) {
		bool check = false;
		for (int j = 1; j < s[i].length(); ++j) {
			string pref = s[i].substr(0, j);
			string suff = s[i].substr(j, s[i].length()-j);
			if (m[pref] && m[suff]) {
				check = true;
			}
		}
		if (check) {
			ans += '1';
		} else {
			ans += '0';
		}
	}
	return ans;
}

int main() {
	int t, n;
	cin >> t;
	string res[t];
	for (int i = 0; i < t; ++i) {
		cin >> n; 
		map<string, bool> m;
		string s[n];
		for (int j = 0; j < n; ++j) {
			cin >> s[j];
			m[s[j]] = true;
		}
		res[i] = solve(n, s, m);
	}

	for (int i = 0; i < t; ++i) {
		cout << res[i] << '\n';
	}

	return 0;
}
