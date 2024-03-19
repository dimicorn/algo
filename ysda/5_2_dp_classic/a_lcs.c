#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(int* arr, int n, int* brr, int m) {
    int dp[n+1][m+1];
    for (int i = 0; i <= n; ++i) 
        for (int j = 0; j <= m; ++j)
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (arr[i-1] == brr[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int m;
    scanf("%d", &m);
    int brr[m];
    for (int i = 0; i < m; ++i)
        scanf("%d", &brr[i]);
    int ans = lcs(arr, n, brr, m); 
    printf("%d\n", ans);

    return 0;
}

