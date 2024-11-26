#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int> > pref_max(n+1), pref_min(n+1), post_max(n+1), post_min(n+1);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    pref_max[0] = make_pair(INT_MIN, -1);
    pref_min[0] = make_pair(INT_MAX, -1);
    post_max[n] = make_pair(INT_MIN, n);
    post_min[n] = make_pair(INT_MAX, n);
    for (int i = 1; i <= n; ++i) {
        if (v[i-1] == pref_max[i-1].first)
            pref_max[i] = pref_max[i-1];
        else
            pref_max[i] = (v[i-1] == max(v[i-1], pref_max[i-1].first)) ? make_pair(v[i-1], i-1) : pref_max[i-1];

        if (v[i-1] == pref_min[i-1].first)
            pref_min[i] = pref_min[i-1];
        else
            pref_min[i] = (v[i-1] == min(v[i-1], pref_min[i-1].first)) ? make_pair(v[i-1], i-1) : pref_min[i-1];
    }

    for (int i = n-1; i >= 0; --i) {
        if (v[i] == post_max[i+1].first)
            post_max[i] = make_pair(v[i], i);
        else
            post_max[i] = (v[i] == max(v[i], post_max[i+1].first)) ? make_pair(v[i], i) : post_max[i+1];

        if (v[i] == post_min[i+1].first)
            post_min[i] = make_pair(v[i], i);
        else
            post_min[i] = (v[i] == min(v[i], post_min[i+1].first)) ? make_pair(v[i], i) : post_min[i+1];
    }
    
    int max = INT_MIN, min = INT_MAX;
    int i1, j1, i2, j2;
    for (int i = 0; i < n - 1; ++i) {
        if (min > (pref_min[i+1].first - post_max[i+1].first)) {
            min = pref_min[i+1].first - post_max[i+1].first;
            i1 = pref_min[i+1].second;
            j1 = post_max[i+1].second;
        }
        if (max < (pref_max[i+1].first - post_min[i+1].first)) {
            max = pref_max[i+1].first - post_min[i+1].first;
            i2 = pref_max[i+1].second;
            j2 = post_min[i+1].second;
        }
    }

    cout << i1+1 << ' ' << j1+1 << '\n';
    cout << i2+1 << ' ' << j2+1 << '\n';
    return 0;
}
