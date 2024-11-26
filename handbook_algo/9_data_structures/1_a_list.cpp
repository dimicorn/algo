#include <iostream>
#include <list>
#include <vector>
#include <iterator>

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

    list<int> lst;
    for (int i = 0; i < n; ++i) {
        auto it = lst.begin();
        auto [x, y] = v[i].second;
        if (v[i].first == 1) {
            advance(it, x);
            lst.insert(it, y);
        } else if (v[i].first == 2) {
            advance(it, x-1);
            cout << *it << '\n';
        } else {
            advance(it, x-1);
            lst.erase(it);
        }
    }


    return 0;
}
