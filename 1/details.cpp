#include <bits/stdc++.h>

using namespace std;

int details (int n, int k, int m) {
    int numb_z = n / k;
    int numb_d = k / m * numb_z;
    int r = n % k + k % m * numb_z;
    while (r / k != 0) {
        numb_z = r / k;
        numb_d += k / m * numb_z;
        r = r % k + k % m * numb_z;
    }
    return numb_d;
}
int main() {
    int n, k, m;
    cin >> n >> k >> m;

    if (n >= k && k >= m) {
        cout << details(n, k, m) << '\n';
    } else {
        cout << "0\n";
    }
    
    return 0;
}