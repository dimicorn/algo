#include <stdio.h>

int solve(const char* arr, const int n, int k, const char ch) {
    int l = 0, r, ans = 0;
    for (r = 0; r < n; ++r) {
        if (arr[r] != ch) 
            --k;
        if (k < 0) {
            if (arr[l] != ch) 
                ++k;
            ++l;
        }
    }   
    return r - l;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char arr[n];
    int count_a = 0, count_b = 0;
    for (int i = 0; i < n; ++i)
        scanf(" %c", &arr[i]);
    int res1 = solve(arr, n, k, 'a');
    int res2 = solve(arr, n, k, 'b');
    int ans = (res1 > res2) ? res1 : res2;
    printf("%d\n", ans);

    return 0;
}

