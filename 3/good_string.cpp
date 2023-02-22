#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long int g = 0;
    cin >> n;
    int c[n];
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        g += min(c[i], c[i + 1]);
    }
    cout << g << '\n';
}