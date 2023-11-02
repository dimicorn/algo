#include <bits/stdc++.h>

using namespace std;

int solve(int* arr, int l, int r) {
    int min = *min_element(arr + l, arr + r + 1);
    int max = *max_element(arr + l, arr + r + 1);
    if (min == max) return -1;
    else return max;
}

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int l, r, res;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        res = solve(arr, l, r);
        if (res == -1) cout << "NOT FOUND\n";
        else cout << res << '\n';
    }

    return 0;
}
