#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    cout << *min_element(x, x+n) << ' ' << *min_element(y, y+n) << ' ';
    cout << *max_element(x, x+n) << ' ' << *max_element(y, y+n) << '\n';
    
    return 0;
}