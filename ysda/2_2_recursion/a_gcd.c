#include <stdio.h>
#define ll unsigned long long

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b); 
    return gcd(a, b-a);
}


int main() {
    int n;
    scanf("%d", &n);
    ll arr[n];
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%llu", &x);
        if (i == 0)
            arr[i] = x;
        else
            arr[i] = gcd(x, arr[i-1]);
    }   
    printf("%lld\n", arr[n-1]);
    return 0;
}

