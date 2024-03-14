#include <stdio.h>
#define ll long long

ll calc(ll a, ll b, ll mod) {
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    ll y;
    if (b % 2 == 0) {
        y = calc(a, b / 2, mod);
        y = (y * y) % mod;
    } else {
       y = a % mod;
       y = (y * calc(a, b-1, mod) % mod) % mod;
    }   
    return (y + mod) % mod; 
}

int main() {
    ll a, b, mod;
    scanf("%lld %lld %lld", &a, &b, &mod);
    ll ans = calc(a, b, mod);
    printf("%lld\n", ans);

    return 0;
}

