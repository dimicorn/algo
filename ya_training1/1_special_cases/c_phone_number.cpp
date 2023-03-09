#include <bits/stdc++.h>

using namespace std;

long int to_numb(string s) {
    long int res = 0;
    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
            ++count;
        }
    }
    if (count == 11) {
        int f = res / 1e10;
        if (f == 7) {
            res += 1e10;
        }
    } else if (count == 7) {
        res += 8495e7;
    }

    return res;
}

int main(int argc, char* argv[]) {
    string numb, s1, s2, s3;
    cin >> numb >> s1 >> s2 >> s3; 

    if (to_numb(numb) == to_numb(s1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    if (to_numb(numb) == to_numb(s2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    if (to_numb(numb) == to_numb(s3)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

