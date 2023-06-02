#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string s, t;
    cin >> s >> t;
    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) {
            count++;
        }
    }
    cout << count;
    return 0;
}

