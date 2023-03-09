#include <iostream>
#include <vector>
#include <algorithm>


int main(int argc, char *argv[]) {
    int n, summ = 0;
    std::cin >> n;
    std::vector<int> groups(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> groups[i];
    }
    std::sort(groups.begin(), groups.end());
    for (int i = 0; i < n / 2 + 1; ++i) {
        summ += groups[i] / 2 + 1;
    }
    std::cout << summ;
    return 0;
}

