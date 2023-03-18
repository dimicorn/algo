#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int brr[n+1];
    brr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        brr[i] = arr[i-1] + brr[i-1];
    }
    int l = 0;
    int count = 0;
    for (int r = 1; r <= n; ++r) {
        if (l >= n) {
            break;
        }
        if (brr[r] - brr[l] == k) {
            count++;
            ++l;
        } else if (brr[r] - brr[l] > k) {
            ++l;
            --r;
        }
        // cout << l << ' ' << r << ' ' << count << '\n';
    }
    cout << count << '\n';
    return 0;
}