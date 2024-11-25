#include <iostream>

using namespace std;

bool leap_year(const int &x) {
    if (x % 400 == 0)
        return true;
    else if (x % 100 == 0)
        return false;
    else if (x % 4 == 0)
        return true;
    return false;
}
int main() {
    int m, y;
    cin >> m >> y;
    if (m != 2) {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            cout << "31\n";
        else
            cout << "30\n";
    } else {
        if (leap_year(y))
            cout << "29\n";
        else
            cout << "28\n";
    }
    return 0;
}
