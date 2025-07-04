#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n / 5 >= 1) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};

int main() {
    auto sol = new Solution();
    cout << sol->trailingZeroes(10) << '\n';
    return 0;
}
