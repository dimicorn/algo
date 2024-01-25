#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        int** dp = new int*[n+1];
        for (int i = 0; i <= n; ++i)
            dp[i] = new int[m+1];
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        int res = dp[n][m];
        for (int i = 0; i < n; ++i)
            delete [] dp[i];
        delete [] dp;

        return res;
    }
};

int main() {
    string text1 = "bl", text2 = "yby";
    Solution* sol = new Solution();
    cout << sol->longestCommonSubsequence(text1, text2) << '\n';

    return 0;
}
