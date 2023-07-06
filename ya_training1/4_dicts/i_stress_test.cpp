#include <bits/stdc++.h>

using namespace std;

string tol(string s) {
	for (auto &i : s) {
		i = tolower(i);
	}
	return s;
}

bool check(string s) {
	int count = 0;
	for (auto &i : s) {
		if ('a' <= i && i <= 'z') {
			continue;
		} else {
			count++;
		}
	}
	if (count == 1) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int n;
	cin >> n;
	unordered_map<string, unordered_set<string>> m;
	string s, s_l;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		m[tol(s)].insert(s);
	}
	int count = 0;
	while(cin >> s) {
		s_l = tol(s);
		if (m.find(s_l) != m.end() && m[s_l].find(s) != m[s_l].end()) {
			continue;
		} else if (m.find(s_l) != m.end() && m[s_l].find(s) == m[s_l].end()) {
			count++;
		} else if (check(s)) {
			continue;
		} else {
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}
