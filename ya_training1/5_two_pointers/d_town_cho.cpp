#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int d[n];
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    int l = 0;
    long long int count = 0;
    for (int r = 1; r < n; ++r) {
        // cout << l << ' ' << r << '\n';
        if (d[r] - d[l] > k) {
            count += n - r;
            ++l;
            --r;
        }
    }
    cout << count << '\n';

    return 0;
}