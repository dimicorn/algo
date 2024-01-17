#include <bits/stdc++.h>
#include <random>

using namespace std;

class Solution {
public:
    int rand7() {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist7(1,7);
        return dist7(rng);
    }
    Solution() {
        int n = 0;
        for (int r = 0; r < 7; ++r) {
            for (int c = 0; c < 7; ++c) {
                table[r][c] = n % 10;
                ++n;
            }
        }
    }
    int rand10() {
        while (true) {
            int row = rand7() - 1;
            int col = rand7() - 1;
            if (row == 6 || row == 5 && col >= 5) continue;
            return table[row][col] + 1;
        }
    }
private:
    int table[7][7];
};

int main() {
    Solution* sol = new Solution();
    cout << sol->rand10() << '\n';

    return 0;
}
