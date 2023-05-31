#include <iostream>

using namespace std;

int bins(int arr[], int l, int r, int x) {
    int m = (r + l) / 2;
    while (l <= r) {
        if (arr[m] == x) {
            return m + 1;
        } else if (arr[m] > x) {
            return bins(arr, l, m-1, x);
        } else if (arr[m] < x) {
            return bins(arr, m+1, r, x);
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    int n, m;
    cin >> n >> m;
    int arr[n], brr[m], res[m];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> brr[i];
        res[i] = bins(arr, 0, n-1, brr[i]);
    }
    for (int i = 0; i < m; ++i) {
        cout << res[i] << ' ';
    }
    return 0;
}

