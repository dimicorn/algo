#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int s[4];
    s[0] = max(a, c) * (b + d);
    s[1] = max(a, d) * (b + c);
    s[2] = max(b, c) * (a + d);
    s[3] = max(b, d) * (a + c);

    sort(s, s + 4);
    if (s[0] == max(a, c) * (b + d)) {
        cout << max(a, c) << ' ' << b + d << '\n';
    } else if (s[0] == max(a, d) * (b + c)) {
        cout << max(a, d) << ' ' << b + c << '\n';
    } else if (s[0] == max(b, c) * (a + d)) {
        cout << max(b, c) << ' ' << a + d << '\n';
    } else if (s[0] == max(b, d) * (a + c)) {
        cout << max(b, d) << ' ' << a + c << '\n';
    }

    return 0;
}