#include <iostream>
 
using namespace std;
 
int main()
{
    string s;
    int t, c;
    t = 0;
    c = 0;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < 5; ++i){
        for (int j = t; j < len + 1; ++j){
            if (s[j] == 'h' and c == 0){
                t = j + 1;
                ++c;
                break;
            }
            else if (s[j] == 'e' and c == 1){
                t = j + 1;
                ++c;
                break;
            }
            else if (s[j] == 'l' and (c == 2 or c == 3)){
                t = j + 1;
                ++c;
                break;
            }
            else if (s[j] == 'o' and c == 4){
                t = j + 1;
                ++c;
                break;
            }
        }
    }
    if (c == 5){
        cout << "YES";
        }
    else {
        cout << "NO";
        }
    return 0;
}
