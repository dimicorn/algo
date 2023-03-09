#include <iostream>
#include <set>

int main(int argc, char* argv[]) {
    int x, y, z, n;
    std::set<int> s, ss;
    std::cin >> x >> y >> z >> n;
    ss.insert(x);
    ss.insert(y);
    ss.insert(z);
    while (n > 0) {
        int t = n % 10;
        s.insert(t);
        n /= 10;
    }
    int count = 0;
    for (auto i: s) {
        if (ss.find(i) == ss.end()) {
            count++;
        }
    }
    std::cout << count << "\n"; 
    return 0;
}

