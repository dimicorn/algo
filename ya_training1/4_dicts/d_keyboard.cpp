#include <iostream>
#include <map>

int main(int argc, char* argv[]) {
    int n, k, c, p;
    std::cin >> n;
    std::map<int, int> m; 
    for (int i = 0; i < n; ++i) {
        std::cin >> c;
        m[i] = c;
    }
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> p;
        m[p - 1]--;
    }
    for (int i = 0; i < n; ++i) {
        if (m[i] >= 0) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }

    return 0;
}

