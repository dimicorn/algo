#include <stdio.h>

void hanoi(int n, int start, int end) {
    if (n == 1) {
        printf("%d %d\n", start, end);
        return;
    }   
    int temp = 6 - start - end;
    hanoi(n-1, start, temp);
    printf("%d %d\n", start, end);
    hanoi(n-1, temp, end);
}


int main() {
    int n;
    scanf("%d", &n);
    int res = 1 << n;
    printf("%d\n", res - 1); 
    hanoi(n, 1, 3); 
    return 0;
}

