#include <iostream>
#include <fstream>
#include <string>
#include <set>


int main(int argc, char* argv[]) {
    std::ifstream file;
    file.open("input.txt");
    std::string word;
    std::set<std::string> s;
    while (file >> word) {
       s.insert(word);
    }
    std::cout << s.size() << "\n";
    return 0;
}

