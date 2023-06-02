#include <iostream>

using namespace std;

double fact(int x) {
    double res = 1;
    for (int i = 1; i <= x; ++i) {
        res *= i;
    }
    return res;
}

double C(int n, int k) {
    return fact(n) / (fact(k) * fact(n-k));
}


int main(int argc, char* argv[]) {
    int k, m, n;
    cin >> k >> m >> n;
    double res = 1 - (2*m*n + 4 * C(n,2) + C(m, 2)) / (4 * C(k+m+n, 2));
    cout << res;
    return 0;
}

