#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, x, a;
	cin >> n >> x;
	pair<long long, long long> arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> a;
		arr[i].first = a;
		arr[i].second = i;
	}
	sort(arr, arr+n);
	int l = 0;
	int r = n - 1;
	pair<long long, long long> ind;
	bool sol = false;
	while (l < r) {
		if (arr[l].first + arr[r].first == x) {
			sol = true;
			ind.first = arr[l].second+1;
			ind.second = arr[r].second+1;
			break;
		} else if (arr[l].first + arr[r].first < x) {
			++l;
		} else {
			--r;
		}
	}
	if (sol) {
		cout << ind.first << ' ' << ind.second << '\n';
	} else {
		cout << "-1\n";
	}

	return 0;
}
