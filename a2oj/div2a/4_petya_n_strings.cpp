#include <iostream>
 
using namespace std;
 
int main()
{
    string a, b, s1, s2;
    a = "";
    b = "";
    cin >> s1;
    cin >> s2;
    int len = s1.length();
    for (int i = 0; i < len + 1; ++i){
        a += (char)tolower(s1[i]);
        b += (char)tolower(s2[i]);
    }
    if (a > b){
        cout << 1;
    }
    else if (a < b){
        cout << -1;
    }
    else{
        cout << 0;
    }
    return 0;
}
