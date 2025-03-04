#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        for (long long i = 15; i >= 0; --i) {
            if (n < pow(3, i))
                continue;
            else
                n -= pow(3, i);
        }
        return n == 0;
    }
};

int main() {
    auto sol = new Solution();
    int n = 12;
    if (sol->checkPowersOfThree(n))
        cout << "TRUE\n";
    else 
        cout << "FALSE\n";
    return 0;
}
