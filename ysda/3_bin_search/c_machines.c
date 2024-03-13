#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define ll long long int

ll max_element(const ll* arr, const int* n) {
    ll max = LLONG_MIN;
    for (int i = 0; i < *n; ++i)
        if (max < arr[i])
            max = arr[i];
    return max;
}

bool check(const ll* arr, const int* n, const ll* mid, const ll* t) {
    ll sum = 0;
    for (int i = 0; i < *n; ++i) {
        sum += (*mid / arr[i]);
        if (sum >= *t) 
            return true;
    }   
    return false;
}

int main() {
    int n;
    ll t;
    scanf("%d %lld", &n, &t);
    ll arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);
    ll l = 1, r = t * max_element(arr, &n);
    ll ans;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(arr, &n, &mid, &t)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }   
    printf("%lld\n", ans);
    
    
    return 0;
}
