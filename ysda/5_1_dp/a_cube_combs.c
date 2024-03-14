#include <stdio.h>
#define ll long long

int main() {
    ll mod = 1e9 + 7;
    int n;
    scanf("%d", &n);
    ll dp[n + 1]; 
    for (int i = 1; i <= n; ++i)
        dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 6 && j <= i; ++j) 
            dp[i] = (dp[i] + dp[i - j]) % mod;
    printf("%lld\n", dp[n]);
    return 0;
}

