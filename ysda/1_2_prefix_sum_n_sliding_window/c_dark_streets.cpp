#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p, x, r;
	cin >> n >> p;
	vector<int> lights(p+1, 0);
    int left, right;
	for (int i = 0; i < n; ++i) {
		cin >> x >> r;
		left = max(0, x - r);
		right = min(x + r + 1, p);
        ++lights[left];
        --lights[right];
	}
    for (int i = 1; i <= p; ++i)
        lights[i] += lights[i-1];

    int count, ans = 0;
    for (int i = 0; i <= p; ++i) {
        count = 0;
        while (lights[i] != 1 && i <= p) {
            ++count;
            ++i;
        }
        ans = max(ans, count);
    }

    cout << ans << '\n';
    return 0;
}
