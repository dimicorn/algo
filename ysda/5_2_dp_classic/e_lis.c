#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max_element(int* arr, int n) {
    int ans = arr[0];
    for (int i = 1; i < n; ++i)
        ans = max(ans, arr[i]);
    return ans;
}

int lis(int* arr, int n) {
    int dp[n];
    for (int i = 0; i < n; ++i)
        dp[i] = 1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1); 

    return max_element(dp, n); 
}

int main() {
    int n, ans;
    scanf("%d", &n);
    int arr[n];
    for (int j = 0; j < n; ++j)
        scanf("%d", &arr[j]);
    ans = lis(arr, n); 
    printf("%d\n", ans);

    return 0;
}

