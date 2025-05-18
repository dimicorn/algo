#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};

int main() {
    auto sol = new Solution();
    cout << sol->hammingWeight(11) << '\n';
    return 0;
}
