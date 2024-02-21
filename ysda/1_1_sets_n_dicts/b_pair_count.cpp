#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, a;
	cin >> n >> k;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		s.insert(a);
	}
	int count = 0;
	for (auto &it : s) {
		if (s.find(abs(k - it)) != s.end() && abs(k - it) != it) {
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}
