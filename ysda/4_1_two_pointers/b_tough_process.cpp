#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n], ans[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int l = 0, r, pos;
    int res = 0;
    for (r = 0; r < n; ++r) {
        if (arr[r] == 0)
            --k;
        if (k < 0) {
            if (arr[l] == 0)
                ++k;
            ++l;
        }
        if ((r - l + 1) > res) {
            res = r - l + 1;
            pos = l;
        }
    }
    cout << res << '\n';
    for (int i = 0; i < n; ++i) {
        if (pos <= i && i < pos + res) {
            cout << 1 << ' ';
        } else {
            cout << arr[i] << ' ';
        }
    }
    cout << '\n';

    return 0;
}
