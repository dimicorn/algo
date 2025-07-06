#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string tmp = "";
        for (const auto& letter : s) {
            if (letter == ' ') {
                words.push_back(tmp);
                tmp = "";
            } else {
                tmp += letter;
            }
        }
        words.push_back(tmp);

        if (words.size() != pattern.length())
            return false;

        unordered_map<char, string> m;
        unordered_map<string, char> m2;
        for (int i = 0; i < words.size(); ++i) {
            if (m.find(pattern[i]) == m.end() &&
                m2.find(words[i]) == m2.end()) {
                m[pattern[i]] = words[i];
                m2[words[i]] = pattern[i];
            } else if (m[pattern[i]] == words[i] &&
                m2[words[i]] == pattern[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;

    }
};
