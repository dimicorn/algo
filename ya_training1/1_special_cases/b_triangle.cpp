#include <iostream>


int main(int argc, char* argv[]) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}

