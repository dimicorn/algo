#include <bits/stdc++.h>

using namespace std;

int main() {
    int g, s;
    string word, sentence;
    cin >> g >> s;
    cin >> word >> sentence;
    int count = 0;
    set<char> letters, temp;
    for (auto const &l : word) {
        letters.insert(l);
    }
    for (int i = 0; i < s - g; ++i) {
        temp = letters;
        for (int j = 0; j < g; ++j) {
            if (temp.find(sentence[i+j]) != temp.end()) {
                temp.erase(sentence[i+j]);
            }
        }
        if (temp.size() == 0) {
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}