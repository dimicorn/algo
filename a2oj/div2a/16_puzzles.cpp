#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[m];
    int q = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < m; ++i){
        cin >> arr[i];
    }
    sort(arr, arr + q);
    int s = arr[n-1] - arr[0];
    for (int i = 0; i < m; ++i){
        if (s > arr[n+i-1]-arr[i] and n+i-1 < m){
            s = arr[n+i-1]-arr[i];
        }
    }
    cout << s;
    return 0;
}
