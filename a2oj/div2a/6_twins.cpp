#include <iostream>
 
using namespace std;
 
int main()
{
    int t, c, summ;
    c = 0;
    summ = 0;
    cin >> t;
    int coins[t];
    for (int i = 0; i < t; ++i){
        cin >> coins[i];
        summ += coins[i];
    }
    for (int i = 0; i < t; ++i){
        for (int j = 0; j < t; ++j){
            if (coins[j] > coins[j+1] and j + 1 != t){
                int temp = coins[j];
                coins[j] = coins[j+1];
                coins[j+1] = temp;
            }
        }
    }
    for (int i = t - 1; i >= 0; --i){
        c += coins[i];
        if(c > summ - c){
            cout << t - i;
            break;
        }
    }
    return 0;
}
