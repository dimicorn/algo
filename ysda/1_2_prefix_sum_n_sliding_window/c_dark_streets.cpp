#include <bits/stdc++.h>

using namespace std;

struct interval {
	int l, r;
};

vector<interval> merge(vector<interval> v) {
	vector<interval> res;
	res.push_back(v[0]);
	for (int i = 1; i < v.size(); ++i) {
		if (v[i].l <= res[i-1].r) {
			res[i-1].r = v[i].r;
		} else {
			res.push_back(v[i]);
		}
	}
	return res;
}
		
int main() {
	int n, p, x, r;
	cin >> n >> p;
	int points = p + 1;
	interval arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> x >> r;
		arr[i].l = max(0, x - r);
		arr[i].r = min(x + r, p);
	}
	sort(arr, arr+n, [](auto const &x, auto const &y){return x.l < y.l;});

	vector<interval> dark;

	interval inter;
	for (int i = 1; i < n; ++i) {
		if (arr[i].l < arr[i-1].r) {
			if (arr[i].r < arr[i-1].r) {
				// полное вложение
				inter.l = arr[i].l;
				inter.r = arr[i].r;
				dark.push_back(inter);
			} else {
				// вложения нет, просто пересечение
				inter.l = arr[i].l;
				inter.r = arr[i-1].r;
				dark.push_back(inter);
			}
		} else {
			// points -= (arr[i-1].r - arr[i-1].l + 1);
			continue;
		}
	}
	vector<interval> d = merge(dark);
	
	

	return 0;
}
