#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int a, b, c;

    cin >> a >> b >> c;

    if (c < 0) {
        cout << "NO SOLUTION\n";
    } else if (a != 0) {
        if ((c * c - b) % a == 0) {
            cout << (c * c - b) / a;
        } else {
            cout << "NO SOLUTION\n";
        }
    } else if (b < 0) {
        cout << "NO SOLUTION";
    } else {
        if ((c * c == b)) {
            cout << "MANY SOLUTIONS\n";
        } else {
            cout << "NO SOLUTION\n";
        }
    }

    return 0;
}

