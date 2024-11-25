#include <bits/stdc++.h>

using namespace std;

int lower_bound(int* arr, int n, int k) {
    int l = 0, r = n - 1, mid;
    while (l < r) {
        mid = (r + l) / 2;
        if (arr[mid] >= k) 
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int upper_bound(int* arr, int n, int k) {
    int l = 0, r = n - 1, mid;
    while (l < r) {
        mid = (r + l) / 2;
        if (arr[mid] <= k) 
            l = mid + 1;
        else
            r = mid;
    }
    return l;
} 

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> k;
    int brr[k];
    for (int i = 0; i < k; ++i)
        cin >> brr[i];

    for (int i = 0; i < k; ++i) {
        int up = upper_bound(arr, n, brr[i]);
        int low = lower_bound(arr, n, brr[i]);
        int res = up - low;
        if (arr[up] == brr[i]) {
            ++res;
        }
        cout << res << ' ';
    }
    cout << '\n';

    return 0;
}
