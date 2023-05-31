#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string s, res;
    res = "";
    cin >> s;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == 'A') {
            res += 'T';
        } else if (s[i] == 'T') {
            res += 'A';
        } else if (s[i] == 'C') {
            res += 'G';
        } else if (s[i] == 'G') {
            res += 'C';
        }
    }

    cout << res << '\n';
    return 0;
}

