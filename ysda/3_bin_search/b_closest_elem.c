#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(long long*)a - *(long long*)b);
}

int lower_bound(const long long* arr, const int* n, const long long* x) {
    int l = 0, r = *n, mid;
    while (l < r) {
        mid = (r + l) / 2;
        if (*x <= arr[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }   
    return l;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long long arr[n], brr[m];
    for (int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);
    for (int i = 0; i < m; ++i)
        scanf("%lld", &brr[i]);
    long long res;
    for (int i = 0; i < m; ++i) {
        if (brr[i] <= arr[0]) {
            res = arr[0];
        } else if (brr[i] >= arr[n-1]) {
            res = arr[n-1];
        } else {
            long long* bs = (long long*) bsearch(&brr[i], arr, n, sizeof(long long), cmp);
            if (bs != NULL) {
                res = brr[i];
            } else {
                int lb = lower_bound(arr, &n, &brr[i]);
                if (lb - 1 >= 0 && abs(arr[lb-1] - brr[i]) <= abs(arr[lb] - brr[i])) {
                    res = arr[lb-1];
                } else {
                    res = arr[lb];
                }
            }
        }
        printf("%lld ", res);
    }   
    printf("\n");
    return 0;
}

