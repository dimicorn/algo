#include <bits/stdc++.h>

using namespace std;

struct problem {
	int a, d;
};

int main() {
	int n;
	cin >> n;
	problem arr[n];
	for (int i = 0; i < n; ++i) {
		problem p;
		cin >> p.a >> p.d;
		arr[i] = p;
	}
	sort(arr, arr+n, [](auto const &x, auto const &y){return x.a < y.a;});
	/*
	for (auto &it : arr) {
		cout << it.a << ' ' << it.d << '\n';
	}
	*/
	long long int f = 0;
	long long int prof = 0;
	for (int i = 0; i < n; ++i) {
		f += arr[i].a;
		prof += arr[i].d - f;
	}
	cout << prof << '\n';

	return 0;
}
