#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<long long int> s;
	int count = 0;
	long long int a;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (s.find(a) == s.end()) {
			count++;
			s.insert(a);
		}
	}

	cout << count << '\n';
	
	return 0;
}
