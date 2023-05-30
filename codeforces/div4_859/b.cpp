#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int a, t, n;
    cin >> t;
    string ans[t];
    for (int i = 0; i < t; ++i) {
        cin >> n;
        int m = 0;
        int b = 0;
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (a % 2 == 0) {
                m += a;
            } else {
                b += a;
            }
        }
        if (m > b) {
            ans[i] = "YES";
        } else {
            ans[i] = "NO";
        }
 
    }
    for (int i = 0; i < t; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
