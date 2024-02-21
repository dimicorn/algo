#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr+n);
    int l = 0, r;
    for (r = 0; r < n; ++r)
        if (arr[r] - arr[l] > 5)
            ++l;
    cout << r - l << '\n';

    return 0;
}
