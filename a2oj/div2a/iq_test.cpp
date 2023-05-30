#include <iostream>
#include <algorithm>


struct Number {
    int n, ind;
};

int main(int argc, char* argv[]) {
    int n, numb;
    std::cin >> n;
    Number arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> numb;
        Number N {numb, i};
        arr[i] = N;
    }
    auto comp = [](Number a, Number b){return a.n % 2 < b.n % 2;};
    std::sort(arr, arr + n, comp);
    if (arr[0].n % 2 == 0 && arr[1].n % 2 == 0) {
        std::cout << arr[n - 1].ind + 1 << "\n";
    } else {
        std::cout << arr[0].ind + 1 << "\n";
    }
    return 0;
}

