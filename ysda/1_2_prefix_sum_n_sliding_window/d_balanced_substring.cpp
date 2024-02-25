#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	string s;
	cin >> n >> s;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    int zeroes = 0, ones = 0, ans = 0;
    int balance;
    unordered_map<int, int> m;
    m[0] = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ++zeroes;
        else ++ones;
        balance = ones - zeroes;
        if (m.find(balance) != m.end()) ans = max(ans, i - m[balance]);
        else m[balance] = i;
    }
    cout << ans << '\n';
	return 0;
}
