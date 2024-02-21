#include <bits/stdc++.h>

using namespace std;

long long solve(long long n) {
	set<long long> s;
	for (long long i = 1; i * i * i <= n; ++i) {
		s.insert(i * i * i);
	}
	for (long long i = 1; i * i <= n; ++i) {
		s.insert(i * i);
	}
	return s.size();
}

int main() {
	int t;
	long long n;
	cin >> t;
	long long ans[t];
	for (int i = 0; i < t; ++i) {
		cin >> n;
		ans[i] = solve(n);
	}
	for (int i = 0; i < t; ++i) {
		cout << ans[i] << '\n';
	}

	return 0;
}
