#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int a, b, c, t;
    cin >> t;
    char ans[t];
    for (int i = 0; i < t; ++i) {
        cin >> a >> b >> c;
        if (a + b == c) {
           ans[i] = '+';
        } else {
            ans[i] = '-';
        }
    }
    for (int i = 0; i < t; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
