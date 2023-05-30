#include <iostream>
#include <cmath>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (x1 != x2 && y1 != y2 && abs(x1 - x2) != abs(y1 - y2)) {
        std::cout << -1;
    } else if (x1 == x2) {
        std::cout << x1 + abs(y1 - y2) << " " << y1 << " " << x2 + abs(y1 - y2) << " " << y2;
    } else if (y1 == y2) {
        std::cout << x1 << " " << y1 + abs(x1 - x2) << " " << x2 << " " << y2 + abs(x1 - x2);
    } else {
        std::cout << x1 << " " << y2 << " " << x2 << " " << y1;
    }
    return 0;
}
