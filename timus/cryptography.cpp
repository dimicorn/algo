#include <iostream>

// not working
bool IsPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

long long prime(int n) {
    int count = 0;
    long long i = 2;
    while (count < n) {
        if (IsPrime(i)) {
            count++;
        }
        i++;
    }
    return i - 1;
}

int main(int argc, char *argv[]) {
    int k;
    std::cin >> k;
    int arr[k];
    for (int i = 0; i < k; ++i) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < k; ++i) {
        std::cout << prime(arr[i]) << "\n";
    }
    return 0;
}

