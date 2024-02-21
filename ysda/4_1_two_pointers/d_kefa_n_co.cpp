#include <bits/stdc++.h>

using namespace std;

struct Friend {
    int value, money;
};

int main() {
    int n, d;
    cin >> n >> d;
    Friend arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i].money >> arr[i].value;
    sort(arr, arr+n, 
    [](auto const &x, auto const &y) {return x.money < y.money;});
    int l = 0, r = 0;
    long long sum = 0, res = 0;
    while (l <= r && r < n) {
        if (arr[r].money - arr[l].money < d) {
            sum += arr[r].value;
            ++r;
        } else {
            sum -= arr[l].value;
            ++l;
        }
        res = max(res, sum);
    }
    cout << res << '\n';

    return 0;
}
