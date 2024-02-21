#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
 
	for (int i = 0; i < n;) {
		int zeros = 0;
		int ones = 0;
		while (i < n && s[i] == '0') {
			++i;
			++zeros;
		}

		while (i < n && s[i] == '1') {
			++i;
			++ones;
		}

		ans = max(ans, min(zeros, ones));
	}
 
	cout << ans * 2 << '\n';
	
	return 0;
}
