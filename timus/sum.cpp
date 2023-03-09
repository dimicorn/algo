#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n, summ = 0;
    cin >> n;
    if (n > 1) {
        for (int i = 1; i <= n; ++i) {
            summ += i;
        }
        cout << summ;
    } else if (n < 1) {
        for (int i = 1; i >= n; --i) {
            summ += i;
        }
        cout << summ;
    } else {
        cout << 1;
    }
    return 0;
}

