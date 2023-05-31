#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string s, res;
    res = "";
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'T') {
            res += 'U';
        } else {
            res += s[i];
        }
    }
    cout << res << '\n';
    return 0;
}

