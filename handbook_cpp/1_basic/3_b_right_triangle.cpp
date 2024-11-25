#include <iostream>
#include <cmath>

using namespace std;

int euclid(const int &x, const int &y) {
    return x * x + y * y;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b < c || a + c < b || b + c < a) {
        cout << "UNDEFINED\n";
    } else if (
        euclid(a, b) == c * c || 
        euclid(a, c) == b * b ||
        euclid(b, c) == a * a
        ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
