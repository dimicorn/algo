#include <bits/stdc++.h>

using namespace std;

struct rect {
    int min_plus, max_plus, min_minus, max_minus;
};

rect extend(rect r, int d) {
    r.min_plus -= d;
    r.max_plus += d;
    r.min_minus -= d;
    r.max_minus += d;
    return r;
}

rect intersect(rect r1, rect r2) {
    rect ans;
    ans.min_plus = max(r1.min_plus, r2.min_plus);
    ans.max_plus = min(r1.max_plus, r2.max_plus);
    ans.min_minus = max(r1.min_minus, r2.min_minus);
    ans.max_minus = min(r1.max_minus, r2.max_minus);
    return ans;
}

vector<pair<int, int>> solve(int t, int d, int n, pair<int, int> arr[]) {
    int nav_x, nav_y, x, y;
    rect pos_rect = {0, 0, 0, 0};
    rect nav_rect;
    vector<pair<int, int>> res;

    for (int i = 0; i < n; ++i) {
        pos_rect = extend(pos_rect, t);
        nav_x = (arr[i]).first;
        nav_y = (arr[i]).second;
        nav_rect.min_plus = nav_x + nav_y;
        nav_rect.max_plus = nav_x + nav_y;
        nav_rect.min_minus = nav_x - nav_y;
        nav_rect.max_minus = nav_x - nav_y;
        nav_rect = extend(nav_rect, d);
        pos_rect = intersect(pos_rect, nav_rect);
    }
    
    for (int i = pos_rect.min_plus; i <= pos_rect.max_plus; ++i) {
        for (int j = pos_rect.min_minus; j <= pos_rect.max_minus; ++j) {
            if ((i + j) % 2 == 0) {
                x = (i + j) / 2;
                y = i - x;
                res.push_back(make_pair(x, y));
            }
        }
    }

    return res;
}

int main() {
    int t, d, n;
    cin >> t >> d >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    vector<pair<int, int>> ans = solve(t, d, n, arr);
    cout << ans.size() << '\n';
    for (auto const &coord : ans) {
        cout << coord.first << ' ' << coord.second << '\n';
    }
    return 0;
}