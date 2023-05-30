#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string s, n;
    n = "";
    int c = 0;
    int a = 0;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; ++i){
        if (s[i] == 'W' and s[i+1] == 'U' and s[i+2] == 'B' and i+2 < len){
            i += 2;
            ++c;
        }
        else{
            if (c != 0){
                c = 0;
                //char l = s[i];
                n += ' ';
                n += s[i];
            }
            else{
                n += s[i];
            }
        }
    }
    //cout << n << endl;
    if (n[0] == ' '){
        for (int i = 1; i < n.length(); ++i){
            cout << n[i];
        }
    }
    else{
        for (int i = 0; i < n.length(); ++i){
            cout << n[i];
        }
    }
    return 0;
}
