#include <bits/stdc++.h>
 
using namespace std;
 
bool check(int n, string s) {
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            return false;
        }
    }
    return true;
}
 
int main() {
    int n, t;
    cin >> t;
    string ans[t];
    for (int i = 0; i < t; ++i) {
        cin >> n;
        string str;
        cin >> str;
        map<char, char> m;
        m[str[0]] = '0';
        string temp = "";
        temp += m[str[0]];
        for (int j = 1; j < n; ++j) {
            if (str[j] != str[j-1] && m.find(str[j]) == m.end()) {
                if (m[str[j-1]] == '0') {
                    m[str[j]] = '1';
                } else {
                    m[str[j]] = '0';
                }
            }
            temp += m[str[j]];
        }
        if (check(n, temp)) {
            ans[i] = "YES";
        } else {
            ans[i] = "NO";
        }
    }
 
    for (int i = 0; i < t; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
