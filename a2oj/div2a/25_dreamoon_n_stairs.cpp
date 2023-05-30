#include <iostream>


int main(int argc, char* argv[]) {
    int n, m, count = 0;
    std::cin >> n >> m;
    if (n < m) {
        std::cout << -1 << "\n";
    } else {
        while (n > 0) {
            if (!(n % 2 == 0 && (count + n / 2) % m == 0)) {
                n--;
                count++;
            } else {
                count += n / 2;
                break;
            }
        }
        if (count % m == 0) {
            std::cout << count << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    }
    return 0;
}

