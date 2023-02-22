#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file;
    file.open("input.txt");
    string word;
    map<char, int> letters;
    int max = 0;
    while (file >> word) {
        for (int i = 0; i < word.length(); ++i) {
            if (letters.find(word[i]) == letters.end()) {
                letters[word[i]] = 1;
            } else {
                letters[word[i]]++;
            }
        }
    }
    file.close();
    for (auto const & item : letters) {
        if (item.second > max) {
            max = item.second;
        }
    }
    for (int i = max; i >= 0; --i) {
        if (i > 0) {
            for (auto const & item : letters) {
                if (item.second >= i) {
                    cout << '#';
                } else {
                    cout << ' ';
                }
            }
        } else {
            for (auto const & item : letters) {
                cout << item.first;
            }
        }
        cout << '\n';
    }

    return 0;
}