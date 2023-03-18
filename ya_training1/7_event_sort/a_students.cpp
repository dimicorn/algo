#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a, b, c, d;
    cin >> n >> m;
    set<pair<int, int>> s;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        for (auto const &pair: s) {
            c = pair.first;
            d = pair.second;
            if (a <= d && c <= b) {
                cout << "hi\n";
                s.erase(pair);
                s.insert(make_pair(min(a, c), max(b, d)));
                break;
            }
        }
    }
    cout << "hi\n";
    for (auto const &pair : s) {
        cout << pair.first << ' ' << pair.second << '\n';
    }
    return 0;
}
