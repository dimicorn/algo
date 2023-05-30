#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    if (t%2 == 0 and t!=2){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
