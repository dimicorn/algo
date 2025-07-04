#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (const auto &i : magazine) {
            if (m.find(i) == m.end())
                m[i] = 1;
            else
                ++m[i];
        }
        for (const auto &i : ransomNote) {
            if (m.find(i) == m.end()) {
                return false;
            } else {
                --m[i];
                if (m[i] < 0)
                    return false;
            }
        }

        return true;
    }
};

int main() {
    string ransomNote = "aa";
    string magazine = "aab";
    auto sol = new Solution();
    auto res = sol->canConstruct(ransomNote, magazine);
    if (res)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
