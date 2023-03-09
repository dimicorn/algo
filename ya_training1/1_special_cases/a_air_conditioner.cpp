#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
    int troom, tcond;
    std::string s;
    std::cin >> troom >> tcond;
    std::cin >> s;
    if (s == "freeze") {
        if (troom <= tcond) {
            std::cout << troom;
        } else {
            std::cout << tcond;
        }
    } else if (s == "heat") {
        if (troom >= tcond) {
            std::cout << troom;
        } else {
            std::cout << tcond;
        }
    } else if (s == "auto") {
        std::cout << tcond;
    } else if (s == "fan") {
        std::cout << troom;
    }
    return 0;
}

