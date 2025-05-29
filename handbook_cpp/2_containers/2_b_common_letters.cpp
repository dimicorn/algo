#include <iostream>
#include <string>
#include <set>

int main() {
    std::string word;
    std::set<char> res;
    bool first = true;
    while (std::cin >> word) {
        if (first) {
            for (const auto& letter : word)
                res.insert(letter);
            first = false;
            continue;
        }
        std::set<char> tmp, intersect;
        for (const auto& letter : word)
            tmp.insert(letter);
        std::set_intersection(
            res.begin(), res.end(),
            tmp.begin(), tmp.end(),
            std::inserter(intersect, intersect.begin()));
        res = std::move(intersect);
    }
    for (const auto& letter : res)
        std::cout << letter;
    std::cout << '\n';

    return 0;
}
