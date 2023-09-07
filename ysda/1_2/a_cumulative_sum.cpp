#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	int pref[n+1];
	pref[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		pref[i+1] = arr[i] + pref[i];
	}
	int m;
	cin >> m;
	int res[m];
	int l, r;
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		res[i] = pref[r+1] - pref[l];
	}
	for (int i = 0; i < m; ++i) {
		cout << res[i] << '\n';
	}

	return 0;
}
