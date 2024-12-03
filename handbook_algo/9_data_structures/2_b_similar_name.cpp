#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int countPairs(const vector<vector<string> >& prepared, const int &m) {
    int answer = 0;
    for (int i = 0; i < m; ++i) {
        unordered_map<string, int> suffix_map, word_map;
        for (const auto &suff: prepared) {
            string suffix = suff[i], word = suff[m];
            if (suffix_map.find(suffix) != suffix_map.end()) {
                int repeats = (word_map.find(word) != word_map.end()) ? word_map[word]: 0;
                answer += suffix_map[suffix] - repeats;
            }
            if (suffix_map.find(suffix) == suffix_map.end())
                suffix_map[suffix] = 1;
            else
                ++suffix_map[suffix];
            if (word_map.find(word) == word_map.end())
                word_map[word] = 1;
            else
                ++word_map[word];
        }
    }

    return answer;
}

int main() {
    int n, m;
    string str;
    cin >> n;
    vector<vector<string> > prepared(n);
    for (int i = 0; i < n; ++i) {
        cin >> str;
        m = str.length();
        vector<string> tmp(m+1);
        for (int j = 0; j < m; ++j)
            tmp[j] = str.substr(0, j) + str.substr(j+1);
        tmp[m] = str;
        prepared[i] = tmp;
    }

    cout << countPairs(prepared, m) << '\n';
    return 0;
}
