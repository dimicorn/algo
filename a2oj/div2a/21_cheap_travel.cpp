#include <iostream>


int main(int argc, char* argv[]) {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    if (b >= a * m) {
        std::cout << n * a;
    } else {
        int x = n / m;
        int numb = n - m * x;
        if (numb * a > b) {
            std::cout << (x + 1) * b;
        } else {
            std::cout << x * b + numb * a;
        }
    } 
    return 0;
}

