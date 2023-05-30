#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int f0 = 0;
    int f1 = 1;
    int fi;
    if (n == 0) {
        cout << "0\n";
    } else if (n == 1) {
        cout << "1\n";
    } else {
        for (int i = 0; i < n-1; ++i) {
            fi = f0 + f1;
            f0 = f1;
            f1 = fi;
        }
        cout << fi << '\n';
    }
    
    return 0;
}