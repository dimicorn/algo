#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int max_element(const int* arr, const int* n) {
    int max = INT_MIN;
    for (int i = 0; i < *n; ++i)
        if (max < arr[i])
            max = arr[i];
    return max;
}

bool check(const int* arr, const int* n, const int* mid, const int* k) {
    int sum = 0;
    for (int i = 0; i < *n; ++i) {
        sum += arr[i] / *mid;
        if (sum >= *k) 
            return true;
    }   
    return false;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int l = 1, r = max_element(arr, &n);
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(arr, &n, &mid, &k)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }   
    printf("%d\n", ans);

    return 0;
}

