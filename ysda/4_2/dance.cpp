#include <bits/stdc++.h>

using namespace std;

int count(int* arr, int* brr, int n, int m) {
	int l = 0;
	int r = 0;
	int c = 0;
	while (l < n && r < m) {
		if (abs(arr[l]-brr[r]) <= 1) {
			l++;
			r++;
			c++;
		} else if (brr[r]-arr[l] > 1) {
			l++;
		} else {
			r++;
		}
	}
	return c;

}

int main() {
	int n, m;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cin >> m;
	int brr[m];
	for (int i = 0; i < m; ++i) {
		cin >> brr[i];
	}
	sort(arr, arr+n);
	sort(brr, brr+m);

	if (n < m) {
		cout << count(arr, brr, n, m) << '\n';
	} else {
		cout << count(brr, arr, m, n) << '\n';
	}

	return 0;
}
