#include <iostream>
 
using namespace std;
 
int main()
{
    string s, s2;
    cin >> s;
    s2 = "";
    int len = s.length();
    for (int i = 0; i < len + 1; ++i){
        if (s[i] != '+'){
            s2 += s[i];
        }
    }
    int len2 = s2.length();
    for (int i = 0; i < len2 + 1; ++i){
        for(int j = 0; j < len2 + 1; ++j){
            if (int(s2[j]) > int(s2[j+1]) and j + 1 != len2){
                char t = s2[j];
                s2[j] = s2[j+1];
                s2[j+1] = t;
            }
        }
    }
    if (len2 == 2){
        cout << s2[1];
    }
    else{
        cout << s2[1];
        for (int i = 2; i < len2; ++i){
        cout << '+' << s2[i];
        }
    }
 
    return 0;
}
