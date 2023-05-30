#include <iostream>
 
using namespace std;
 
int main()
{
    int c, n, m;
    c = 0;
    cin >> n >> m;
    while (n*m > 0){
        ++c;
        --n;
        --m;
    }
    if (c%2 == 0){
        cout << "Malvika";
    }
    else{
        cout << "Akshat";
    }
    return 0;
}
