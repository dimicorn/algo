#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    int ppl;
    if (b == 1) {
        ppl = a * 2 - 1;
    } else if (b == 2) {
        ppl = a * 2;
    }
    int f = ppl - k;
    int beh = ppl + k;
    int f_t = f / 2 + f % 2;
    int b_t = beh / 2 + beh % 2;
    if (abs(f_t - a) >= abs(b_t - a) && ppl + k <= n) {
        if (beh % 2 == 0) {
            cout << b_t << " 2\n";
        } else {
            cout << b_t << " 1\n";
        }
    } else if (ppl - k > 0) {
        if (f % 2 == 0) {
            cout << f_t << " 2\n";
        } else {
            cout << f_t << " 1\n";
        }
    } else {
        cout << "-1\n";
    }
    
    return 0;
}