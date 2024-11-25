#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    if (x % 400 == 0)
        cout << "YES\n";
    else if (x % 100 == 0)
        cout << "NO\n";
    else if (x % 4 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
