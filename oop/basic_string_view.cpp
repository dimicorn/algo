#include <iostream>
#include <string>
#include <stdexcept>

class NonOwningChars {
private:
    const char** ptr;
    unsigned int len;

public:
    NonOwningChars(const char** s) {
        ptr = s;
        len = std::strlen(*s);
    }

    const char operator[](const unsigned int &index) {
        if (0 <= index && index < len) {
            return *(*ptr + index);
        }
        throw std::invalid_argument("Invalid string index!");
    }
            
};

class NonOwningString {
private:
    const std::string* ptr;
    unsigned int len;

public:
    NonOwningString(const std::string &s) {
        ptr = &s;
        len = s.length();
    }

    const char operator[](const unsigned int &index) {
        if (0 <= index && index < len) {
            return (*ptr)[index];
        }
        throw std::invalid_argument("Invalid string index!");
    }
};

int main() {
    /*
    const char* s = "abc";
    const char** ptr = &s;
    NonOwningChars nos(ptr);
    std::cout << nos[1] << '\n';
    */

    std::string s = "abc";
    NonOwningString nos(s);
    std::cout << nos[1] << '\n';

    return 0;
}
