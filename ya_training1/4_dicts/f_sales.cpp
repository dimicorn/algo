#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file;
    string line, surname, item, temp;
    long long int amount;
    file.open("input.txt");
    map<string, map<string, long long int>> dict;
    while (file >> surname >> item >> amount) {
        if (dict.find(surname) == dict.end()) {
            dict[surname][item] = amount;
        } else if (dict[surname].find(item) == dict[surname].end()) {
            dict[surname][item] = amount;
        } else {
            dict[surname][item] += amount;
        }
    }
    file.close();
    for (auto const &i : dict) {
        cout << i.first << ":\n";
        for (auto const &j : i.second) {
            cout << j.first << ' ' << j.second << '\n';
        }
    }
    return 0;
}