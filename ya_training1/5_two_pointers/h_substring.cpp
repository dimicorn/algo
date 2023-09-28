#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	string str;
	cin >> n >> k;
	cin >> str;

	map<char, int> m;
	int l = 0, r = 0;
	int max = 0;
	int first = 0;
	while (l <= r && r < n) {
		if (m.find(str[r]) == m.end()) {
			m[str[r]] = k - 1;
		} else {
			--m[str[r]];
		}

		while (m[str[r]] < 0) {
			++m[str[l]];
			++l;
		}
		if ((r - l + 1) > max) {
			max = r - l + 1;
			first = l + 1;
		}
		++r;
	}

	printf("%d %d\n", max, first);


	return 0;
}
