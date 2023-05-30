#include <iostream>
 
using namespace std;
 
int main()
{
    int m[5][5];
    int x, y, ans;
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if (m[i][j] == 1){
                x = i;
                y = j;
            }
        }
    }
    ans = abs(x-2) + abs (y - 2);
    cout << ans;
    return 0;
}
