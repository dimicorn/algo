#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, a, b, c, d;
    cin >> m >> n;
    set<pair<int, int>> segs;
    for (int i = 0; i < n; ++i) {
        cin >> c >> d;
        for (auto it = segs.begin(); it != segs.end();) {
            a = (*it).first;
            b = (*it).second;
            if (a <= d && c <= b) {
                it = segs.erase(it);
            } else {
                ++it;
            }
        }
        segs.insert(make_pair(c, d));
    }
    cout << segs.size() << '\n';

    return 0;
}