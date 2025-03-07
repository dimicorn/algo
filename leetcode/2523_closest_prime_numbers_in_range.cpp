#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_prime(right+1, true);
        is_prime[0] = false;
        is_prime[1] = false;
        int num = 2;
        while (num * num <= right) {
            if (is_prime[num]) {
                for (int mult = num * num; mult < right + 1; mult += num)
                    is_prime[mult] = false;
            }
            ++num;
        }
        vector<int> primes;
        for (int i = 0; i < right+1; ++i)
            if (is_prime[i] && left <= i)
                primes.push_back(i);
        if (primes.size() < 2)
            return {-1, -1};
        int l = primes[0];
        int r = primes[primes.size()-1]; 
        int res = r - l;
        for (int i = 1; i < primes.size(); ++i) {
            int diff = primes[i] - primes[i-1];
            if (res > diff) {
                res = diff;
                l = primes[i-1];
                r = primes[i];
            }
        }
        return {l, r};
    }
};

int main() {
    auto sol = new Solution();
    int left = 10;
    int right = 19;
    auto res = sol->closestPrimes(left, right);
    cout << res[0] << ' ' << res[1] << '\n';
    return 0;
}
