#include <iostream>
 
using namespace std;
 
int main()
{
    int n, x, y, z, x0, y0, z0;
    x = 0;
    y = 0;
    z = 0;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x0 >> y0 >> z0;
        x += x0;
        y += y0;
        z += z0;
    }
    if (x == 0 and y == 0 and z == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
