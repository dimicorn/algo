#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;

    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        if (v[i].first == 1) {
            s.insert(v[i].second);
        } else {
            if (s.find(v[i].second) == s.end())
                cout << "0\n";
            else
                cout << "1\n";
        }
    }

    return 0;
}
