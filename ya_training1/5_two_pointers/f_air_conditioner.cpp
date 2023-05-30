#include <bits/stdc++.h>

using namespace std;

struct ac {
    int price, power;
};

int main() {
    int power, price, n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> m;
    map<int, int> M;
    for (int i = 0; i < m; ++i) {
        cin >> power >> price;
        if (M.find(power) == M.end()) {
            M[power] = price;
        } else {
            M[power] = min(M[power], price);
        }
    }
    m = M.size();
    ac brr[m];
    int i = 0;
    for (auto const &it : M) {
        brr[i].power = it.first;
        brr[i].price = it.second;
        ++i;
    }

    int prefix[m + 1];
    prefix[m] = brr[m-1].price;
    for (i = m-1; i >= 0; --i) {
        prefix[i] = min(prefix[i+1], brr[i].price);
    }

    int sum = 0;
    int l = 0;
    int r = 0;
    // cout << '\n';
    while(l < n && r < m) {
        // cout << l << ' ' << r << '\n';
        if (brr[r].power >= arr[l]) {
            sum += prefix[r];
            ++l;
            --r;
        }
        ++r;
    }
    /*
    cout << '\n';
    for (auto const &it : brr) {
        cout << it.power << ' ' << it.price << '\n';
    }
    cout << '\n';
    for (auto const &it : prefix) {
        cout << it << '\n';
    }
    cout << '\n';
    */
    cout << sum << '\n';

    return 0;
}