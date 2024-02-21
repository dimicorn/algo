#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    unordered_map<int, int> hash;
    int l = 0, r = 0;
    int count = k, res = 0;
    int ansr = -1, ansl = -1;
    while (l <= r && r < n) {
        if (hash.find(arr[r]) != hash.end()) {
            ++hash[arr[r]];
            ++r;
        } else {
            hash[arr[r]] = 1;
            --k;
            ++r;
        }
        if (k < 0) {
            --hash[arr[l]];
            if (hash[arr[l]] == 0) {
                hash.erase(arr[l]);
                ++k;
            }
            ++l;
        }
        if (hash.size() <= count && res < r - l + 1) {
            res = r - l + 1;
            ansl = l;
            ansr = r;
        }
    }

    cout << ansl+1 << ' ' << ansr << '\n';
    return 0;
}
