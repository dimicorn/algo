#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> v(n), res(n);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v[i] = x - 1;
    }
    for (int i = 0; i < n; ++i)
        res[v[i]] = i+1;

    for (const auto &i : res)
        cout << i << ' ';
    return 0;
}
