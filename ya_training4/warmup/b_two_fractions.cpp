#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int num = a * d + b * c;
    int denum = b * d;

    // cout << num << ' ' << denum << '\n';
    int coef = gcd(num, denum);
    
    cout << num / coef << ' ' << denum / coef << '\n';

    return 0;
}
