#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bit(n);
        string str = bit.to_string();
        reverse(str.begin(), str.end());
        bitset<32> res(str);
        return res.to_ulong();
    }
};

int main() {
    uint32_t n = 43261596;
    auto sol = new Solution();
    cout << sol->reverseBits(n) << '\n';
    return 0;
}
