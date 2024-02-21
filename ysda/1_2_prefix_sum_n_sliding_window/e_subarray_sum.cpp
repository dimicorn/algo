#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int count = 0;
	int sum = arr[0];
	int l = 0;
	int r = 0;
	while (l <= r && r < n) {
		if (sum == x) {
			++count;
			sum -= arr[l];
			++l;
			++r;
			sum += arr[r];
		} else if (sum < x) {
			++r;
			sum += arr[r];
		} else {
			sum -= arr[l];
			if (l == r) {
				++r;
				sum += arr[r];
			}
			++l;
		}
	}

	cout << count << '\n';

	return 0;
}
