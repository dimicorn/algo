#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int l = 0;
    int r = 0;
    int colors[k] = {};
    int count = 0;
    int min = n + 1;
    int l_m = -1, r_m = -1;
    while (l <= r && r < n) {
        if (colors[arr[r]-1] == 0) {
            colors[arr[r]-1]++;
            count++;
        } else {
            colors[arr[r]-1]++;
        }
        if (count == k) {
            if (min > r - l) {
                min = r - l;
                r_m = r;
                l_m = l;
            }
            if (colors[arr[l]-1] == 1) {
                count--;
            }
            colors[arr[l]-1]--;
            l++;
            r--;
        }
        r++;
        cout << l << ' ' << r << '\n';
    }
    cout << l_m+1 << ' ' << r_m+1 << '\n';
    return 0;
}