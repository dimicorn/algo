#include <bits/stdc++.h>

using namespace std;

struct coord {
    int x, y;
};
struct track {
    int s, f;
};
int main() {
    int n, m;
    cin >> n;
    coord arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].x >> arr[i].y;
    }
    cin >> m;
    track brr[m];
    for (int i = 0; i < m; ++i) {
        cin >> brr[i].s >> brr[i].f;
    }
    int prefsum1[n], prefsum2[n];
    prefsum1[0] = 0, prefsum2[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].y - arr[i-1].y > 0) {
            prefsum1[i] = arr[i].y - arr[i-1].y + prefsum1[i-1];
            prefsum2[i] = prefsum2[i-1];
        } else if (arr[i].y - arr[i-1].y < 0) {
            prefsum1[i] = prefsum1[i-1];
            prefsum2[i] = arr[i-1].y - arr[i].y + prefsum2[i-1];
        } else {
            prefsum1[i] = prefsum1[i-1];
            prefsum2[i] = prefsum2[i-1];
        }
    }
    // cout << prefsum1[n] << ' ' << prefsum2[n] << '\n';
    for (int i = 0; i < m; ++i) {
        if (brr[i].f > brr[i].s) {
            cout << prefsum1[brr[i].f - 1] - prefsum1[brr[i].s - 1] << '\n';
        } else if (brr[i].f < brr[i].s) {
            cout << prefsum2[brr[i].s - 1] - prefsum2[brr[i].f - 1] << '\n';
        } else {
            cout << "0\n";
        }
    }
    return 0;
}