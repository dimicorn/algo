#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, count = 0;
    long long t;
    cin >> n >> m >> t;
    n--;
    m--;
    while (true) {
        if (t - (n + m) * 2 > 0) {
            t -= (n + m) * 2;
            n -= 2;
            m -= 2;
            count++;
        } else {
            break;
        }
    }
    cout << count << '\n';
    return 0;
}
