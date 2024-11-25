#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 2; ++i)
        cout << "   ";
    if (n != 1)
        cout << "  ";
    for (int i = 1; i <= k; ++i) {
        if (i <= 9) {
            if ((i + n - 1) % 7 == 1)
                cout << ' ' << i;
            else if ((i + n - 1) % 7 == 0)
                cout << "  " << i << '\n';
            else
                cout << "  " << i;
        } else {
            if ((i + n - 1) % 7 == 1)
                cout << i;
            else if ((i + n - 1) % 7 == 0)
                cout << " " << i << '\n';
            else
                cout << " " << i;

        }
        if (i == k && !((i + n - 1) % 7 == 0))
            cout << '\n';
    }
    return 0;
}
