#include <iostream>
#include <algorithm>


int main(int argc, char* argv[]) {
    int n, k;
    std::cin >> n >> k;
    int count = 0;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + n);
    /*
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    */
    for (int i = 0; i < n; i += 3) {
        if (arr[i + 2] + k <= 5 && i + 2 < n) {
            count++;
        }
    }
    std::cout << count << "\n";
    return 0;
}

