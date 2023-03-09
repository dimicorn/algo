#include <iostream>
#include <vector>

struct Coord {
    int x, y;
};

int main(int argc, char* argv[]) {
    int n, m, k, x, y;
    std::vector<Coord> v;
    std::cin >> n >> m >> k;
    int arr[n + 2][m + 2];
    std::fill(*arr, *arr + (m + 2) * (n + 2), -2);
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < k; ++i) {
        std::cin >> x >> y;
        Coord c {x, y};
        v.push_back(c);
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            for (int p = 0; p < k; ++p) {
                if (i == v[p].x && j == v[p].y) {
                    arr[i][j] = -1;
                }
            }
        }
    }
    /*
    std::cout << "Output:\n";
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    */
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (arr[i][j] != -1) {
                if (arr[i - 1][j] == -1) {
                    arr[i][j]++;
                }
                if (arr[i][j - 1] == -1) {
                    arr[i][j]++;
                }
                if (arr[i + 1][j] == -1) {
                    arr[i][j]++;
                }
                if (arr[i][j + 1] == -1) {
                    arr[i][j]++;
                }
                if (arr[i - 1][j - 1] == -1) {
                    arr[i][j]++;
                }
                if (arr[i + 1][j + 1] == -1) {
                    arr[i][j]++;
                }
                if (arr[i - 1][j + 1] == -1) {
                    arr[i][j]++;
                }
                if (arr[i + 1][j - 1] == -1) {
                    arr[i][j]++;
                }
            }
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (arr[i][j] == -1) {
                std::cout << "* ";
            } else {
                std::cout << arr[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}

