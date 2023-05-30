#include <iostream>
#include <cctype>
 
using namespace std;
 
int main()
{
    string s, s2;
    s2 = "";
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len + 1; ++i){
        s2 += (char)tolower(s[i]);
    }
    for (int i = 0; i < len; ++i){
        if (s2[i] != 'o' and s2[i] != 'a' and s2[i] != 'e' and s2[i] != 'y' and s2[i] != 'u' and s2[i] != 'i'){
            cout << '.' << s2[i];
        }
    }
    return 0;
}
