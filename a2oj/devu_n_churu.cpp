#include <iostream>


int main(int argc, char* argv[]) {
    int n, d, t;
    std::cin >> n >> d;
    int arr[n];
    int summ = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        summ += t;
        if (i != n - 1) {
            summ += 10;
            count += 2;
        }
    }
    if (summ > d) {
        std::cout << -1 << "\n";
    } else {
        count += (d - summ) / 5;
        std::cout << count << "\n";
    }

    
    return 0;
}

