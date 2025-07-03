#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] != word[i-1])
                continue;
            ++res;
        }
    
        return res;
    }
};

int main() {
    string word = "ere";
    auto sol = new Solution();
    cout << sol->possibleStringCount(word) << '\n';
    return 0;
}
