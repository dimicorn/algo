#include <bits/stdc++.h>

using namespace std;

int bin_search(int* arr, int x, int n) {
    int m;
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        m = (r + l) / 2;
        if (arr[m] < x) {
            l = m + 1;
        } else if (arr[m] > x) {
            r = m - 1;
        } else {
            return m;
        }
    }
    return -1;
}

int least_greater(int* arr, int x, int n) {
    int m;
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r) {
        m = (r + l) / 2;
        if (arr[m] <= x) {
            l = m + 1;
        } else {
            r = m - 1;
            ans = m;
        }
    }
    return ans;
}

int greatest_lesser(int* arr, int x, int n) {
    int m;
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r) {
        m = (r + l) / 2;
        if (arr[m] >= x) {
            r = m - 1;
        } else {
            l = m + 1;
            ans = m;
        }
    }
    return ans;
}

int main() {
    int n, k, s;
    set<int> stickers;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        stickers.insert(s);
    }
    cin >> k;
    int p[k];
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
    }
    int len = stickers.size();
    int st[len];
    int i = 0;
    for (auto const &s : stickers) {
        st[i] = s;
        ++i;
    }
    sort(st, st + len);
    for (int i = 0; i < k; ++i) {
        cout << greatest_lesser(st, p[i], len) + 1 << '\n';
    }
   
    return 0;
}