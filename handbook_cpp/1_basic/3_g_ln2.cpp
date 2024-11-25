#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double res = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        res += pow(-1, i+1) / i;
    }
    cout << res << '\n';
    return 0;
}
