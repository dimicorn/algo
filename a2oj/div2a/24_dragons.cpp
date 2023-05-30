#include <iostream>
#include <vector>
#include <algorithm>

struct Dragon {
    int x, y;
};

int main(int argc, char* argv[]) {
    int s, n, x, y;
    std::cin >> s >> n;
    std::vector<Dragon> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        Dragon d{x, y};
        v[i] = d;
    }
    auto comp = [](Dragon a, Dragon b) {return a.x < b.x;};
    std::sort(v.begin(), v.end(), comp);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s > v[i].x) {
            s += v[i].y;
        } else {
            count++;
            std::cout << "NO";
            break;
        }
    }
    if (count == 0) {
        std::cout << "YES";
    }
    /*
    std::cout << "Output:";
    for (int i = 0; i < n; ++i) {
        std::cout << v[i].x << "\n";
    }
    */
    return 0;
}

