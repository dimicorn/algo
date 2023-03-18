#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> m;
    int brr[m];
    for (int i = 0; i < m; ++i) {
        cin >> brr[i];
    }
    int i = 0;
    int j = 0;
    int diff = max(arr[n-1], brr[m-1]);
    int arr_min, brr_min;
    while (i < n && j < m) {
        if (diff > abs(arr[i] - brr[j])) {
            diff = abs(arr[i] - brr[j]);
            arr_min = arr[i];
            brr_min = brr[j];
        }
        if (arr[i] - brr[j] > 0) {
            ++j;
        } else if (arr[i] - brr[j] < 0) {
            ++i;
        } else {
            break;
        }
    }
    cout << arr_min << ' ' << brr_min << '\n';

    return 0;
}
