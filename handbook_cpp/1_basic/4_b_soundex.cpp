#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;
    string tmp = "";
    tmp += word[0];
    int n = word.length();
    if (n == 1) {
        cout << word << "000\n";
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        if (word[i] == 'a' || word[i] == 'e' ||
            word[i] == 'h' || word[i] == 'i' ||
            word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'w' || word[i] == 'y'
        ) {
            continue;
        } else {
            if (word[i] == 'b' || word[i] == 'f' ||
                word[i] == 'p' || word[i] == 'v'
            ) {
                tmp += '1';
            } else if (word[i] == 'c' || word[i] == 'g' ||
                word[i] == 'j' || word[i] == 'k' ||
                word[i] == 'q' || word[i] == 's' ||
                word[i] == 'x' || word[i] == 'z'
            ) {
                tmp += '2';
            } else if (word[i] == 'd' || word[i] == 't') {
                tmp += '3';
            } else if (word[i] == 'l') {
                tmp += '4';
            } else if (word[i] == 'm' || word[i] == 'n') {
                tmp += '5';
            } else if (word[i] == 'r') {
                tmp += '6';
            }
        }
    }
    string res = "";
    res += tmp[0];
    if (tmp.length() > 1)
        res += tmp[1];
    for (unsigned int i = 2; i < tmp.length(); ++i) {
        if (tmp[i] == tmp[i-1])
            continue;
        else
            res += tmp[i];
    }
    int m = res.length();
    // cout << res << ' ' << m << '\n';
    if (m < 4) {
        for (int i = 0; i < (4 - m); ++i)
            res += '0';
    }
    for (int i = 0; i < 4; ++i)
        cout << res[i];
    cout << '\n';

    return 0;
}
