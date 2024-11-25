#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, k, x, y, count;
    cin >> m >> n >> k;
    vector<vector<char> > v(m, vector<char>(n, '0'));
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        v[x-1][y-1] = '*';
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[i][j] == '*')
                continue;
            count = 0;
            if (i > 0 && v[i-1][j] == '*')
                ++count;
            if (i > 0 && j > 0 && v[i-1][j-1] == '*')
                ++count;
            if (i > 0 && j < n-1 && v[i-1][j+1] == '*')
                ++count;
            if (j > 0 && v[i][j-1] == '*')
                ++count;
            if (j < n-1 && v[i][j+1] == '*')
                ++count;
            if (i < m-1 && v[i+1][j] == '*')
                ++count;
            if (i < m-1 && j > 0 && v[i+1][j-1] == '*')
                ++count;
            if (i < m-1 && j < n-1 && v[i+1][j+1] == '*')
                ++count;
            v[i][j] += count;
        }
    }
    for (auto const &i: v) {
        for (auto const &j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
