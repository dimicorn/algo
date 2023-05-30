#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        string s;
        cin >> s;
        if (s.length() > 10){
            cout << string(s.begin(), s.begin() + 1);
            string sub = string(s.begin() + 1, s.end() - 1);
            cout << sub.length();
            cout << string(s.end() - 1, s.end()) << endl;
        }
        else{
            cout << s << endl;
        }
    }
 
    return 0;
}
