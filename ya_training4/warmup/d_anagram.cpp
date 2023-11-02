#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[26] = {0}, brr[26] = {0};
    string s1, s2;
    cin >> s1 >> s2;
    
    if (s1.length() != s2.length()) {
        cout << "NO\n";
        return 0;
    }

    for (const auto &s : s1) {
        arr[s - 'a']++;
    }
    for (const auto &s : s2) {
        brr[s - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        if (arr[i] != brr[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
