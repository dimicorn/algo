#include <bits/stdc++.h>

using namespace std;

pair<double, double> solve(int n, double arr[], string brr[]) {
    double max = 4000;
    double min = 30;
    double temp;
    const string cl = "closer";
    const string fur = "further";

    for (int i = 1; i < n; ++i) {
        temp = (arr[i] + arr[i-1]) / 2;
        if (arr[i] > arr[i-1] && brr[i-1] == cl) {
            if (temp > min) {
                min = temp;
            }
        } else if (arr[i] <= arr[i-1] && brr[i-1] == cl) {
            if (temp < max) {
                max = temp;
            }
        }

        if (arr[i] > arr[i-1] && brr[i-1] == fur) {
            if (temp < max) {
                max = temp;
            }
        } else if (arr[i] <= arr[i-1] && brr[i-1] == fur) {
            if (temp > min) {
                min = temp;
            }
        }
    }

    return make_pair(min, max);
}
int main() {
    int n;
    cin >> n;
    double arr[n];
    string brr[n-1];
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cin >> arr[i];
        } else {
            cin >> arr[i] >> brr[i-1];
        }
    }
    pair<double, double> ans = solve(n, arr, brr);
    printf("%.6lf %.6lf", ans.first, ans.second);

    return 0;
}