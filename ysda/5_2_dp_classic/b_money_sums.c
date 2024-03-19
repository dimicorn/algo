#include <stdio.h>
#include <stdbool.h>
#define ll long long

void solve(ll* arr, ll n) {
    ll sum = 0;
    for (ll i = 0; i < n; ++i)
        sum += arr[i];
    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= sum; ++j)
            dp[i][j] = false;
    dp[0][0] = true;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j <= sum; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j >= arr[i-1] && dp[i-1][j-arr[i-1]])
                dp[i][j] = true;
        }
    }   
    ll possibleSums[n];
    ll count = 0;
    for (int j = 1; j <= sum; ++j) {
        if (dp[n][j]) {
            possibleSums[count] = j;
            ++count;
        }
    }   
    printf("%lld\n", count);
    for (ll i = 0; i < count; ++i)
        printf("%lld ", possibleSums[i]);
    printf("\n");
}

int main() {
    ll n;
    scanf("%lld", &n);
    ll arr[n];
    for (ll i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);
    solve(arr, n); 

    return 0;
}

