#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int a1 = n + a * (n - 1); 
    int a2 = n + a * (n + 1);
    int b1 = m + b * (m - 1);
    int b2 = m + b * (m + 1);

    if (a2 < b1 || a1 > b2) {
        cout << "-1\n";
    } else {
        cout << max(a1, b1) << ' ' << min(a2, b2) << '\n';
    }
    return 0;
}

