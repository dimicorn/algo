#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int l = 0, r = 0;
    int sum = 0, res = 0;
    while (l <= r && r < n) {
        if (sum + arr[r] <= m) {
            sum += arr[r];
            ++r;
        } else {
            sum -= arr[l];
            ++l;
        }
        res = max(res, sum);
    }

    cout << res << '\n';
    return 0;
}
