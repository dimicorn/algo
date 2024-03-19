#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    return z;
}

int edit_distance(char* str1, char* str2) {
    int n = strlen(str1), m = strlen(str2);
    int dp[n + 1][m + 1]; 
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);

    return dp[n][m];
}

int main() {
    char str1[1000], str2[1000];
    scanf("%s %s", str1, str2);
    int ans = edit_distance(str1, str2);
    printf("%d\n", ans);

    return 0;
}

