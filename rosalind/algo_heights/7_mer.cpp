#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> m;
    int brr[m], res[n+m];
    for (int i = 0; i < m; ++i) {
        cin >> brr[i];
    }
    int i = 0;
    int a = 0;
    int b = 0;
    while ((a < n || b < m) && i < n + m) {
        if (arr[a] < brr[b] && a < n) {
            res[i] = arr[a];
            ++a;
        } else if (brr[b] <= arr[a] && b < m) {
            res[i] = brr[b];
            ++b;
        }
        ++i;
    }
    for (auto &j : res) {
        cout << j << ' ';
    }
    return 0;
}

