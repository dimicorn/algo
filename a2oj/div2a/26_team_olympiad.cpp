#include <iostream>
#include <vector>

int min(int a, int b, int c) {
    int t = std::min(a, b);
    return std::min(t, c);
}

struct Student {
    int t, ind;
};

int main(int argc, char* argv[]) {
    int n, t;
    std::cin >> n;
    std::vector<Student> v1, v2, v3;
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        Student st {t, i};
        if (t == 1) {
            v1.push_back(st);
        } else if (t == 2) {
            v2.push_back(st);
        } else if (t == 3) {
            v3.push_back(st);
        }
    }
    int numb = min(v1.size(), v2.size(), v3.size());
    std::cout << numb << "\n";
    for (int i = 0; i < numb; ++i) {
        std::cout << v1[i].ind + 1 << " " << v2[i].ind + 1 << " " << v3[i].ind + 1 << "\n";
    }
    return 0;
}

