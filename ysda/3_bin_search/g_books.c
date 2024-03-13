#include <stdio.h>

int max(const int a, const int b) {
    return ((a) > (b)) ? (a) : (b);
}

int main() {
    int n;
    long long t;
    scanf("%d %lld", &n, &t);
    long long arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);
    int l = 0, r;
    long long cur = 0;
    int max_books = 0;
    for (r = 0; r < n; ++r) {
        while (cur + arr[r] > t) {
            cur -= arr[l];
            ++l;
        }
        cur += arr[r];
        int tmp = r - l + 1;
        max_books = max(max_books, tmp);
    }   
    printf("%d\n", max_books);

    return 0;
}
