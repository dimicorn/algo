#include <iostream>
#include <map>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    std::ifstream file;
    file.open("input.txt");
    std::string word, res = "";
    std::map<std::string, int> m;
    while (file >> word) {
        if (m.find(word) != m.end()) {
            m[word]++;
        } else {
            m[word] = 0;
        }
        res += std::to_string(m[word]) + " ";
    }
    std::cout << res;
    return 0;
}

