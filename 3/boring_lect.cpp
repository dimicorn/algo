#include <bits/stdc++.h>

using namespace std;

int main() {
    string word;
    cin >> word;
    map<char, long int> letters;
    for (int i = 0; i < word.length(); ++i) {
        if (letters.find(word[i]) == letters.end()) {
            letters[word[i]] = 0;
        }
    }
    for (int i = 0; i < word.length(); ++i) {
        letters[word[i]] += (i+1) * (word.length()-i);
    }

    for (auto const &letter : letters) {
        cout << letter.first << ": " << letter.second << '\n';
    }
    return 0;
}