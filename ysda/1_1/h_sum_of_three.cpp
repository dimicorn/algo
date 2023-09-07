#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	pair<int, int> arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	/*
	// this shit doen't pass time limit
	unordered_map<int, int> m;
	for (int i = 0; i < n; ++i) {
		int tmp = x - arr[i];
		// unordered_map<long long, long long> m;
		for (int j = i + 1; j < n; ++j) {
			int dif = tmp - arr[j];
			if (m.find(dif) != m.end()) {
				cout << m[dif] + 1 << ' ' << j + 1 << ' ' << i + 1 << '\n';
				break;
			}
			m[arr[j]] = j;
		}
		m[arr[i]] = i;
	}
	*/

	// so 2 pointers;
	sort(arr, arr + n);
	for (int l = 0; l < n; ++l) {
		int m = l + 1;
		int r = n - 1;
		while (m < r) {
			int s = arr[l].first + arr[m].first + arr[r].first;
			if (s == x) {
				cout << arr[l].second+1 << ' ' << arr[m].second+1 << ' ' << arr[r].second+1 << '\n';
				return 0;
			} else if (s > x) {
				--r;
			} else {
				++m;
			}
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}
