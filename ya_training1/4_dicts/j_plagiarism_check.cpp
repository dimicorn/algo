#include <bits/stdc++.h>

using namespace std;

string tol(string s) {
	for (auto &i : s) {
		i = tolower(i);
	}
	return s;
}

long long j = 0;

unordered_map<string, pair<long long, long long>> check(string c, string d, unordered_map<string, pair<long long, long long>> m, unordered_set<string> ss, string s) {
	if (c == "no") {
		s = tol(s);
	}
	string temp = "";
	for (auto &i : s) {
		if (isalpha(i) || isdigit(i) || i == '_') {
			temp += i;
		} else {
			if (temp != "" && (!isdigit(temp[0]) || d == "yes" && isdigit(temp[0]) && temp.length() > 1)) {
				if (ss.find(temp) == ss.end() && m.find(temp) == m.end()) {
					m[temp].first = 1;
					m[temp].second = j;
				} else if (ss.find(temp) == ss.end() && m.find(temp) != m.end()) {
					m[temp].first++;
				}
			}
			++j;
			temp = "";
		}
	}
	if (temp != "" && (!isdigit(temp[0]) || d == "yes" && isdigit(temp[0]) && temp.length() > 1)) {
		if (ss.find(temp) == ss.end() && m.find(temp) == m.end()) {
			m[temp].first = 1;
			m[temp].second = j;
		} else if (ss.find(temp) == ss.end() && m.find(temp) != m.end()) {
			m[temp].first++;
		}
		++j;
	}
	return m;
}


int main() {
	string c, d;
	int n;
	cin >> n >> c >> d;
	string s;
	unordered_set<string> ss;
	unordered_map<string, pair<long long, long long>> m;	
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (c == "no") {
			s = tol(s);
		}
		ss.insert(s);
	}
	while (cin >> s) {
		m = check(c, d, m, ss, s);
	}

	long long max = 0;
	long long ind = j + 1;
	string word;
	for (auto &i : m) {
		// cout << i.first << ' ' << i.second.first << ' ' << i.second.second << '\n';
		if (i.second.first > max || i.second.first == max && ind > i.second.second) {
			ind = i.second.second;
			max = i.second.first;
			word = i.first;
		}
	}
	
	cout << word << '\n';

	return 0;
}
