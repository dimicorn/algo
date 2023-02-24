#include <bits/stdc++.h>

using namespace std;

int solve(int arr[], int n) {
    int vas = -1;
    int max = -1;
    int count = 0;
    int place = 1;
    int ind;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] == max) {
            count++;
            ind = i;
            break;
        }
    }
    for (int i = ind + 1; i < n - 1; ++i) {
        if (arr[i] % 10 == 5 && arr[i] > arr[i+1] && count > 0) {
            if (arr[i] > vas) {
                vas = arr[i];
            }
        }
    }
    if (vas == -1) {
        return 0;
    } else {
        for (int i = 0; i < n; ++i) {
            if (arr[i] > vas) {
                place++;
            }
        }
        return place;
    }
    
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr, n) << '\n';
    
    return 0;
}