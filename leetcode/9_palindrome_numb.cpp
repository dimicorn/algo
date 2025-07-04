#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string tmp = to_string(x);
        int l = 0;
        int r = tmp.length() - 1;
        while (l < r) {
            if (tmp[r] != tmp[l])
                return false;
            --r;
            ++l;
        }
        return true;
    }
};

int main() {
    auto sol = new Solution();
    auto res = sol->isPalindrome(121);
    if (res)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
