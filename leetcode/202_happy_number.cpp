#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (true) {
            n = sqr_sum(n);
            if (n == 1)
                return true;
            if (s.find(n) != s.end())
                return false;
            s.insert(n);
        }
    }
    int sqr_sum(int x) {
        int sum = 0;
        while (x > 0) {
            int tmp = x % 10;
            sum += tmp * tmp;
            x /= 10;
        }
        return sum;
    }
};

int main() {
    auto sol = new Solution();
    cout << sol->isHappy(2) << '\n';
    return 0;
}
