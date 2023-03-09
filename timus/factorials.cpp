#include <iostream>
#include <string>


int main(int argc, char *argv[]) {
    int n, k, result = 1;
    std::string excls;
    std::cin >> n >> excls;
    k = excls.length(); 
    while (n > 0) {
        result *= n;
        n -= k;
    }
    std::cout << result;
    return 0;
}

