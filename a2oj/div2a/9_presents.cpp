#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    int a[t];
    int b[t];
    for (int i = 0; i < t; ++i){
        a[i] = i;
        cin >> b[i];
    }
    for (int i = 0; i < t; ++i){
        --b[i];
    }
    for (int i = 0; i < t; ++i){
        for (int j = 0; j < t; ++j){
            if(a[i] == b[j]){
                cout << j+1 << ' ';
            }
        }
    }
    return 0;
}
