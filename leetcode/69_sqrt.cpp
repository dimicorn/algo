#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int l = 1;
        int r = x;
        long long int m;
        while (l < r) {
            m = (r - l) / 2 + l;
            if (m * m == x) {
                return m;
            } else if (r - l == 1) {
                return l;
            } else if (m * m < x) {
                l = m;
            } else {
                r = m;
            }
        }
        return m;
        
    }
};

int main() {
    auto sol = new Solution();
    cout << sol->mySqrt(8) << '\n';
    return 0;
}
