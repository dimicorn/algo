#include <bits/stdc++.h>

using namespace std;

struct seg {
    int l, r;
};

int main() {
    int n;
    cin >> n;
    seg arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i].l >> arr[i].r;
    sort(arr, arr+n, [](auto const &x, auto const &y)
            {return x.l < y.l;});
    vector<seg> res;
    res.push_back(arr[0]);
    for (int i = 1; i < n; ++i) {
        int b = res[res.size()-1].r;
        int c = arr[i].l, d = arr[i].r;
        if (c <= b) {
            res[res.size()-1].r = max(b, d);
        } else {
            res.push_back(arr[i]);
        }
    }
    cout << res.size() << '\n';
    for (auto const &s : res) 
        cout << s.l << ' ' << s.r << '\n';

    return 0;
}
