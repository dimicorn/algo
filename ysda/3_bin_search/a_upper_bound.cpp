#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> arr[n];
    int brr[m];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = 0;
    } 
    auto cmp = [](auto const &x, auto const &y) {return x < y.first;};
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i)
        arr[i].second = i;
    for (int i = 0; i < m; ++i)
        cin >> brr[i];
    for (int i = 0; i < m; ++i) {
        auto res = upper_bound(arr, arr+n, brr[i], cmp);
        if (res == arr + n)
            cout << n << ' ';
        else
            cout << res->second << ' ';
    }
    cout << '\n';
    return 0;
}

