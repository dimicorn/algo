#include <iostream>
 
using namespace std;
 
int main()
{
    string s, n, k;
    n = "";
    s = "";
    int c = 0;
    getline (cin, k);
    for (int i = 0; i < k.length(); ++i){
        if (isalpha(k[i])){
            s += k[i];
        }
    }
    n += s[0];
    for (int i = 0; i < s.length(); ++i){
        for (int j = 0; j < n.length(); ++j){
            if (s[i] == n[j]){
                ++c;
            }
        }
        if (c == 0){
            n += s[i];
        }
        c = 0;
    }
    if (k == "{}"){
        cout << 0;
    }
    else{
        cout << n.length();
    }
    return 0;
}
