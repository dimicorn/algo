#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int x;
    std::unordered_set<int> s;
    while (iss >> x) {
        if (s.find(x) != s.end()) {
            std::cout << "YES\n";
            continue;
        }
        std::cout << "NO\n";
        s.insert(x);
    }
    return 0;
}
