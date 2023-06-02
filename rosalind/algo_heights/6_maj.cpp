#include <iostream>
#include <algorithm>

using namespace std;

int maj(int arr[], int n) {
    int count = 1;
    for (int j = 0; j < n - 1; ++j) {
        if (arr[j] == arr[j + 1]) {
            count++;
        } else {
            count = 1;
        }
        if (count > n/2) {
            return arr[j];
        }
    } 
    return -1;
}

int main(int argc, char* argv[]) {
    int a, k, n;
    cin >> k >> n;
    int res[k] = {-1};
    int arr[n];
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        sort(arr, arr + n); 
        res[i] = maj(arr, n);
    }
    for (auto &i : res) {
        cout << i << ' ';
    }
    return 0;
}

