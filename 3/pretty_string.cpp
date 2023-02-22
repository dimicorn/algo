#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    string str;
    cin >> k >> str;
    int p = 0;
    set<char> letters;

    for (int i = 0; i < str.length(); ++i) {
        if (letters.find(str[i]) == letters.end()) {
            letters.insert(str[i]);
        }
    }
    
    for (auto const &letter : letters) {
        int temp_k = k;
        int r = 0;
        for (int l = 0; l < str.length(); ++l) {
            while (r < str.length()) {
                if (str[r] == letter) {
                    ++r;
                } else if (temp_k > 0) {
                    ++r;
                    --temp_k;
                } else {
                    break;
                }
            }
            if (r - l > p) {
                p = r - l;
            }
            if (str[l] != letter) {
                ++temp_k;
            }
        }
    }
    cout << p << '\n';
    return 0;
}