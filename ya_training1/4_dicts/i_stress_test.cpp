#include <bits/stdc++.h>

using namespace std;

pair<string, int> tol(string s) {
    string res = "";
    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
        res += tolower(s[i]);
        if (s[i] != tolower(s[i])) {
            count++;
        }
    }
    return make_pair(res, count);
}
int main() {
    int n, stress, count = 0;
    string word, key, key_t, sentence, temp = "";
    map<string, set<string>> dict;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        key = tol(word).first;
        dict[key].insert(word);
    }
    getline(cin, word);
    getline(cin, sentence);
    sentence += ' ';
    for (int i = 0; i < sentence.length(); ++i) {
        if (sentence[i] == ' ') {
            key_t = tol(temp).first;
            stress = tol(temp).second;
            if (stress != 1) {
                count++;
            } else {
                for (auto const &j : dict) {
                    if (key_t == j.first && (j.second).find(temp) == (j.second).end()) {
                        count++;
                        break;
                    }
                }
            }
            temp = "";
        } else {
            temp += sentence[i];
        }
    }
    cout << count << '\n';

    return 0;
}