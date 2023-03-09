#include <iostream>


int main(int argc, char* argv[]) {
    int n, x;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cin >> x;
    int ind = 0;
    int dif = abs(x - arr[0]);
    for (int i = 0; i < n; ++i) {
        if (abs(x - arr[i]) < dif) {
            dif = abs(x - arr[i]);
            ind = i;
        }
    }
    std::cout << arr[ind] << "\n";
    return 0;
}

