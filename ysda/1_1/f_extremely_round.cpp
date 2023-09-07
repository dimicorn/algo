#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
	int count = 0;
	for (auto const &t : to_string(x)) {
		if (t != '0') {
			count++;
		}
	}
	return count == 1;
}

int main() {
	int N = 999999;
	vector<int> ans;
	vector<int> res;
	for (int i = 1; i <= N; ++i) {
		if (check(i)) {
			ans.push_back(i);
		}
	}

	int t, n;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		int count = 0;
		for (int j = 0; j < ans.size(); ++j) {
			if (ans[j] <= n) {
				count++;
			}
		}
		res.push_back(count);
	}

	for (auto const &i : res) {
		cout << i << '\n';
	}
	
	return 0;
}
