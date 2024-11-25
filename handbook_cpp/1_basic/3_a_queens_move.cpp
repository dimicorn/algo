#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
        cout << "YES\n";
    else if (y1 == y2)
        cout << "YES\n";
    else if (abs(x2-x1) == abs(y2-y1))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
