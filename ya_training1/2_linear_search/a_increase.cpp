#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::string str;
    std::vector<char> v;
    getline(std::cin, str); 
    bool check = true;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            continue;
        } else {
            v.push_back(str[i]);
        }
    }
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] >= v[i]) {
            check = false;
        }
        // std::cout << check << "\n";
    }
    if (check) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}

