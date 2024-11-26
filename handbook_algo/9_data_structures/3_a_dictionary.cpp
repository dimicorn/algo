#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    vector<pair<int, pair<int, int> > > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        if (v[i].first == 1) {
            cin >> x >> y;
            v[i].second = make_pair(x, y);
        } else {
            cin >> x;
            v[i].second = make_pair(x, -1);
        }
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        auto [x, y] = v[i].second;
        if (v[i].first == 1) {
            m[x] = y;
        } else {
            if (m.find(x) == m.end())
                cout << "-1\n";
            else
                cout << m[x] << '\n';
        }
    }

    return 0;
}  
