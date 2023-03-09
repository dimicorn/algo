#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::string snake(m, '#');
    std::string space(m - 1, '.');
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            std::cout << snake << "\n";
        } else if (count % 2 == 0) {
            std::cout << space << "#\n";
            count++;
        } else {
            std::cout << "#" << space << "\n";
            count++;
        }
    }
    return 0;
}

