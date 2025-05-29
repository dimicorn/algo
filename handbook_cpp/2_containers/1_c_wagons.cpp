#include <iostream>
#include <string>
#include <deque>

void MakeTrain() {
    std::string cmd;
    int num;
    std::deque<int> d;
    while (std::cin >> cmd >> num) {
        if (cmd == "+left") {
            d.push_front(num);
        } else if (cmd == "+right") {
            d.push_back(num);
        } else if (cmd == "-left") {
            if (num >= static_cast<int>(d.size()))
                d.clear();
            else
                d.erase(d.begin(), d.begin() + num);
        } else if (cmd == "-right") {
            if (num >= static_cast<int>(d.size()))
                d.clear();
            else
                d.erase(d.end() - num, d.end());
        }   
    }   
    for (const auto& i : d)
        std::cout << i << ' ';
    std::cout << '\n';
}
int main() {
    MakeTrain(); 
    return 0;
}
