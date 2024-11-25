#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> words;
    string word;
    while (getline(cin, word))
        words.push_back(word);
    sort(words.begin(), words.end(), greater<string>());
    for (const auto &it : words)
        cout << it << '\n';
    return 0;
}
