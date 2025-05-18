#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};

int main() {
    int left = 5;
    int right = 7;
    auto sol = new Solution();
    cout << sol->rangeBitwiseAnd(left, right) << '\n';

    return 0;
}
