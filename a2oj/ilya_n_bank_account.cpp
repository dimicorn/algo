#include <iostream>


int last_numb(int x) {
    return x / 10;
}

int second_last_numb(int x) {
    int t = x % 10;
    return x / 100 * 10 + t;
}

int main(int argc, char* argv[]) {
    int n;
    std::cin >> n;
    if (n >= 10) {
        std::cout << n;
    } else {
        int res1 = last_numb(n);
        int res2 = second_last_numb(n);
        if (res1 > res2) {
            std::cout << res1;
        } else {
            std::cout << res2;
        }
    }

    return 0;
}

