#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, w, h;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> w >> h;
        if (m.find(w) == m.end()) {
            m[w] = h;
        } else if (m[w] < h) {
            m[w] = h;
        }
    }
    long long int max_height = 0;
    for (auto const &item : m) {
        max_height += item.second;
    }
    cout << max_height << '\n';

    return 0;
}