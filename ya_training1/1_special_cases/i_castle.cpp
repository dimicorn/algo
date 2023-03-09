#include <iostream>

bool check(int a, int b, int c, int d, int e) {
    if ((a <= d && b <= e) || (a <= e && b <= d)) {
        return true;
    } else if ((b <= d && c <= e) || (b <= e && c <= d)) {
        return true;
    } else if ((a <= d && c <= e) || (a <= e && c <= d)) {
        return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    int a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;
    if (check(a, b, c, d, e)) {    
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}

