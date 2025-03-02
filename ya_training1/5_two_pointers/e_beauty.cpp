#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int count_unique = 0;
    int l = 0;
    int r = 0;
    int l_m = 0, r_m = n+1;
    unordered_map<int, int> count;
    for (r = 0; r < n; ++r) {
        if (count.find(arr[r]) == count.end())
            ++count_unique;
        ++count[arr[r]];
        while (k == count_unique) {
            if (r_m - l_m > r - l) {
                r_m = r;
                l_m = l;
            }
            --count[arr[l]];
            if (count[arr[l]] == 0) {
                --count_unique;
                count.erase(count.find(arr[l]));
            }
            ++l;
        }
    }
    cout << l_m+1 << ' ' << r_m+1 << '\n';
    return 0;
}
