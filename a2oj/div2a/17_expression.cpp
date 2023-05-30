#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int arr[] = {a+b+c, (a+b)*c, a+b*c, a*(b+c), a*b+c, a*b*c};
    int q = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr+q);
    cout << arr[5];
    return 0;
}
