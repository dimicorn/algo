#include <stdio.h>
#include <stdbool.h>

bool check(const long long x) {
    const int max_size = 10001;
    long long i;
    long long arr[max_size];
    for (i = 1; i * i * i <= x; ++i)
        arr[i-1] = i * i * i;
    int n = i - 1;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (arr[l] + arr[r] == x)
            return true;
        else if (arr[l] + arr[r] > x)
            --r;
        else
            ++l;
    }   
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    long long arr[t];
    for (int i = 0; i < t; ++i)
        scanf("%lld", &arr[i]);
    for (int i = 0; i < t; ++i) {
        if (check(arr[i]))
            printf("YES\n");
        else
            printf("NO\n");
    }   

    return 0;
}

