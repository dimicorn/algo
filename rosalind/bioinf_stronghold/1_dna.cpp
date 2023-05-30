#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string s;
    cin >> s;
    int count_a = 0;
    int count_c = 0;
    int count_g = 0;
    int count_t = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'A') {
           count_a++;
        } else if (s[i] == 'C') {
           count_c++;
        } else if (s[i] == 'G') {
           count_g++;
        } else if (s[i] == 'T') {
           count_t++;
        }
    }
    cout << count_a << ' ' << count_c << ' ' << count_g << ' ' << count_t << '\n'; 
    return 0;
}

