#include <stdio.h>

struct obj {
    int weight, value;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solve(int s, int n, struct obj* arr) {
    int dp[n+1][s+1];
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= s; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (arr[i-1].weight <= w) {
                dp[i][w] = max(arr[i-1].value + dp[i-1][w-arr[i-1].weight],
                        dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }   
    return dp[n][s];
}

int main() {
    int t;
    scanf("%d", &t);
    int ans[t];
    for (int i = 0; i < t; ++i) {
        int s, n;
        scanf("%d %d", &s, &n);
        struct obj arr[n];
        for (int j = 0; j < n; ++j) {
            scanf("%d %d", &arr[j].weight, &arr[j].value);
        }
        ans[i] = solve(s, n, arr);
    }   
    for (int i = 0; i < t; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}

