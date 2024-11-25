#include <iostream>
#include <string>

using namespace std;

int main() {
    string word, tmp = "";
    getline(cin, word);
    for (const auto &letter: word)
        if (letter != ' ')
            tmp += letter;
    //cout << tmp << '\n';
    if (tmp == "") {
        cout << "YES\n";
        return 0;
    }
    int l = 0, r = tmp.length() - 1;
    while (l <= r) {
        if (tmp[l] != tmp[r]) {
            cout << "NO\n";
            return 0;
        }
        ++l;
        --r;
    }
    cout << "YES\n";
    return 0;
}
