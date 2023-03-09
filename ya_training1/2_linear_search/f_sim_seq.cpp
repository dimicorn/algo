#include <iostream>
#include <vector>

bool check(std::vector<int> v) {
    int n = v.size();
    int j = n - 1;
    for (int i = 0; i < n; ++i) {
        if (v[i] != v[j]) {
            return false;
        }
        j--;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> v(n), buf;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    if (check(v)) {
        std::cout << "0\n";
    } else {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                v.push_back(v[j]);
                buf.push_back(v[j]);
            }
            count++;
            if (check(v)) {
                break;
            } else {
                for (int j = i; j >= 0; --j) {
                    v.pop_back();
                    buf.pop_back();
                }
            }
        }
        /*
        for (int i = 0; i < v.size(); ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
        */
        std::cout << count << "\n";
        for (int i = 0; i < buf.size(); ++i) {
            std::cout << buf[i] << " ";
        }
    }

    for (int i = 0; i < 0; ++i) {
        std::cout << "hi\n";
    }
    return 0;
}

