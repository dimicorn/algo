#include <stdio.h>
#include <stdlib.h>
#define ll long long

typedef struct {
    int start, finish, money;
} job;

int cmp(const void* a, const void* b) {
    job *x = (job *) a;
    job *y = (job *) b;
    return (x->finish > y->finish) - (x->finish < y->finish);
}

int find(job* arr, const int* i) {
    // lower_bound
    int l = 0, r = *i; 
    int mid;
    while (l < r) {
        mid = (r + l) / 2;
        if (arr[*i].start <= arr[mid].finish) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }   
    return l-1;
}

ll max(const ll* a, const ll* b) {
    return (*a > *b) ? *a : *b; 
}

int main() {
    int n;
    scanf("%d", &n);
    job arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d %d %d", &arr[i].start, &arr[i].finish, &arr[i].money);
    qsort(arr, n, sizeof(job), cmp);
    ll dp[n];
    dp[0] = arr[0].money;
    for (int i = 1; i < n; ++i) {
        ll tmp = arr[i].money;
        int search = find(arr, &i);
        if (search != -1)
            tmp += dp[search];
        dp[i] = max(&dp[i-1], &tmp);
    }
    printf("%lld\n", dp[n-1]);

    return 0;
}

