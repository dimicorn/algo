#include <iostream>

using namespace std;

int InsertionSort(int arr[], int n) {
    int count = 0;
    for (int i = 1; i < n; ++i) {
        int k = i;
        while (k > 0 && arr[k] < arr[k-1]) {
            count++;
            swap(arr[k-1], arr[k]);
            --k;
        }
    }
    return count;
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << InsertionSort(arr, n);
    return 0;
}

