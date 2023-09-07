#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, x;
	cin >> n >> x;
	map <long long, long long> m;	
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		int dif = x - arr[i];
		if (m.find(dif) != m.end()) {
			cout << m[dif]+1 << ' ' << i + 1 << '\n';
			return 0;
		}
		m[arr[i]] = i;
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}
