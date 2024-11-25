#include <bits/stdc++.h>

using namespace std;

int bin_search(int* arr, int n, int k) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (r + l) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
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

    for (int i = 0; i < k; ++i)
        cout << bin_search(arr, n, brr[i]) << '\n';
    return 0;
}
