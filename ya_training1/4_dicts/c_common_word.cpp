#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ifstream file;
    file.open("input.txt");
    std::string word;
    std::map<std::string, int> m;
    while (file >> word) {
        if (m.find(word) != m.end()) {
            m[word]++;
        } else {
            m[word] = 0;
        }
    }
    auto max = std::max_element(m.begin(), m.end(), [](const auto &x, const auto &y) {
            return x.second < y.second;});     
    std::cout << max->first << "\n";
    return 0;
}

