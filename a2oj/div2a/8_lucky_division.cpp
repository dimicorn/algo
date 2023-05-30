#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
    string s;
    int b, c, d, g, t;
    b = 0;
    c = 0;
    d = 0;
    g = 0;
    t = 0;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; ++i){
        if (s[i] == '4' or s[i] == '7'){
            ++c;
        }
    }
 
    if (c == len){
        cout << "YES";
    }
    else{
        for (int i = len - 1; i >= 0; --i){
            int a = s[i] - '0';
            t += a * int(pow(10, len - i - 1));
        }
        for (int i = 1; i < t; ++i){
            int e = i;
            int f = i;
            while (e != 0){
                ++b;
                e = e / 10;
            }
            for (int j = 0; j < b; ++j){
                if (f%10 == 4 or f%10 == 7){
                    ++g;
                }
                f = f / 10;
            }
            if (b == g){
                if (t%i == 0){
                   cout << "YES";
                   ++d;
                   break;
                }
            }
            b = 0;
            g = 0;
        }
        if (d == 0){
            cout << "NO";
        }
    }
    return 0;
}
