#include <iostream>
#include <string>
using namespace std;

template <typename T>
void Print(const T& container, const string &delimiter) {
    int n = container.size();
    int i = 0;
    for (const auto &it : container) {
        if (i == n - 1)
             cout << it << '\n';
        else
            cout << it << delimiter;
        ++i;
    }      
}
