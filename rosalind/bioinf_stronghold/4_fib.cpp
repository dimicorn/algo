#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n, k;
    cin >> n >> k;
    int f1 = 1;
    int f2 = 1;
    int fi;
    for (int i = 3; i <= n; ++i) {
        fi = f2 + f1 * k;
        f1 = f2;
        f2 = fi;
    }
    cout << fi << '\n';
    return 0;
}

