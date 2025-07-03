#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string tmp = "a";
        while (tmp.length() < k) {
            int n = tmp.length();
            for (int i = 0; i < n; ++i) {
                if (tmp[i] == 'z')
                    tmp += 'a';
                else
                    tmp += tmp[i] + 1;
            }
        }
        return tmp[k-1];
    }
};

int main() {
    auto sol = new Solution();
    cout << sol->kthCharacter(10) << '\n';
    return 0;
}
