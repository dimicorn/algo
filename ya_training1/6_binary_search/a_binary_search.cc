#include <bits/stdc++.h>

using namespace std;

bool bin_search(int arr[], int x, int l, int r) {
    int m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (arr[m] < x) {
            l = m + 1;
        } else if (arr[m] > x) {
            r = m - 1;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n], brr[k];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> brr[i];
    }
    for (int i = 0; i < k; ++i) {
        if (bin_search(arr, brr[i], 0, n - 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
