#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    deque<int> d;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        if (v[i].first == 1)
            cin >> v[i].second;
        else
            v[i].second = -1;
    }

    for (const auto &i : v) {
        if (i.first == 1)
            d.push_back(i.second);
        else
            d.pop_front();
        
        if (d.size() == 0)
            cout << "-1\n";
        else
            cout << d.front() << '\n';
    }
        
    return 0;
}
