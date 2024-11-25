#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string psswd;
    cin >> psswd;
    int n = psswd.length();
    if (!(8 <= n && n <= 14)) {
        cout << "NO\n";
        return 0;
    }
    vector<int> symbols(4, 0);
    for (int i = 0; i < n; ++i) {
        if (!(33 <= int(psswd[i]) && int(psswd[i]) <= 126)) {
            cout << "NO\n";
            return 0;
        }
        if (!(isalnum(psswd[i]))) {
            ++symbols[0];
        } else if (isdigit(psswd[i])) {
            ++symbols[1];
        } else if (islower(psswd[i])) {
            ++symbols[2];
        } else if (isupper(psswd[i])) {
            ++symbols[3];
        }
    }
    int count = 0;
    for (const auto &it: symbols)
        if (it == 0)
            ++count;
    
    if (count <= 1)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
