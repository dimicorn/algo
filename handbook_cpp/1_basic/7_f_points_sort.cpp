#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int distance(const int &x, const int &y) {
    return x * x + y * y;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), [](const auto &a, const auto &b)
        {return distance(a.first, a.second) < distance(b.first, b.second);
    });
    for (const auto &it : v)
        cout << it.first << ' ' << it.second << '\n';
    return 0;
}
