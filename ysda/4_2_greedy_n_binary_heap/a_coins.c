#include <stdio.h>

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    int count = 0;
    int i = n;
    while (s > 0) {
        if (s >= i) {
            s -= i;
            ++count;
        } else {
            --i;
        }
    }

    printf("%d\n", count);
    return 0;
}

