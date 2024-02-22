#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (n < 26) {
        cout << -1 << '\n';
        return 0;
    }
    int window[26] = {0};
    int count = 0;
    for (int i = 0; i < 26; ++i) {
        if (s[i] == '?') {
            ++count;
            continue;
        }
        ++window[s[i]-'A'];
        if (window[s[i]-'A'] == 1)
            ++count;
    }

    if (count == 26) {
        int cur = 0;
        while (window[cur] > 0) ++cur;
        for (int i = 0; i < 26; ++i) {
            if (s[i] == '?') {
                s[i] = cur + 'A';
                ++cur;
                while (window[cur] > 0) ++cur;
            }
        }
        for (int i = 0; i < n; ++i)
            if (s[i] == '?') s[i] = 'A';
        cout << s << '\n';
        return 0;
    }
    
    for (int i = 26; i < n; ++i) {
        if (s[i] != '?') {
            ++window[s[i]-'A'];
            if (window[s[i]-'A'] == 1)
                ++count;
        } else {
            ++count;
        }
        if (s[i-26] != '?') {
            --window[s[i-26]-'A'];
            if (window[s[i-26]-'A'] == 0)
                --count;
        } else {
            --count;
        }

        if (count == 26) {
            int cur = 0;
            while (window[cur] > 0) ++cur;
            for (int j = i - 25; j <= i; ++j) {
                if (s[j] == '?') {
                    s[j] = cur + 'A';
                    ++cur;
                    while (window[cur] > 0) ++cur;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (s[i] == '?') s[i] = 'A';
            }
            cout << s << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
