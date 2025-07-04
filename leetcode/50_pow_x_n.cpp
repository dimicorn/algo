#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = helper(x, abs(1LL * n));
        if (n >= 0)
            return res;
        return 1.0 / res;
    }
    double helper(double x, long long int n) {
        if (x == 0)
            return 0;
        if (n == 0)
            return 1;
        double res = helper(x * x, n / 2);
        return (n % 2) ? x * res : res;
    }
};

int main() {
    auto sol = new Solution();
    cout << sol->myPow(2.1, 3) << '\n';
    return 0;
}
