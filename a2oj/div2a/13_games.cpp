#include <iostream>
 
using namespace std;
 
int main()
{
    int c, t;
    c = 0;
    cin >> t;
    int a[t], b[t];
    for (int i = 0; i < t; ++i){
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < t; ++i){
        for (int j = 0; j < t; ++j){
            if (a[i] == b[j]){
                ++c;
            }
        }
    }
    cout << c;
    return 0;
}
