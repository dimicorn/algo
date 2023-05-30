#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int b, c, d, t;
    d = 0;
    cin >> t;
    int a[t];
    int n[t];
    for (int i = 0; i < t; ++i){
        cin >> a[i];
        n[i] = 0;
    }
    for (int i = 0; i < t; ++i){
        if (a[i] == *max_element(a, a+t) and d == 0){
            b = i;
            ++d;
        }
        if (a[i] == *min_element(a, a+t)){
            c = i;
        }
    }
    if (b < c){
        cout << b + (t - c - 1);
    }
    else{
        cout << b + (t - c - 2);
    }
    return 0;
}
