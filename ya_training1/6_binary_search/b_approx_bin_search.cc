#include <bits/stdc++.h>

using namespace std;

int greatest_lesser(int arr[], int x, int l, int r) {
    int m, res;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (x < arr[m]) {
            r = m - 1;
            res = r;
        } else {
            l = m + 1;
        }
    }
    cout << res << '\n';
    return arr[res];
}

int least_greater(int arr[], int x, int l, int r) {
    int m, res;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (x > arr[m]) {
            l = m + 1;
            res = l;
        } else {
            r = m - 1;
        }
    }
    return arr[res];
}

int main() {
    int n, k, gl, lg;
    cin >> n >> k;
    int arr[n], brr[k];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> brr[i];
    }
    for (int i = 0; i < k; ++i) {
        gl = greatest_lesser(arr, brr[i], 0, n - 1);
        lg = least_greater(arr, brr[i], 0, n - 1);
        if (abs(gl - brr[i]) <= abs(lg - brr[i])) {
            cout << gl << "hi\n";
        } else {
            cout << lg << '\n';
        }
    }

    return 0;
}
