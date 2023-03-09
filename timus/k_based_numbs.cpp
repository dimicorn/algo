#include <iostream>

#define MAX 20

using namespace std;

int main(int argc, char *argv[]) {
    int n, k;
    long long arr[MAX];
    cin >> n;
    cin >> k;
    arr[0] = 1;
    arr[1] = k - 1;
    for (int i = 2; i <= n; ++i) {
        arr[i] = (k - 1) * (arr[i - 1] + arr[i - 2]);
    }
    cout << arr[n];
    return 0;
}
