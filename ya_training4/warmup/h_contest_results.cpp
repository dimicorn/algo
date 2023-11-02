#include <bits/stdc++.h>

using namespace std;

int main() {
    float a, b, n;
    cin >> a >> b >> n;

    if (ceil(b/n) < a) cout << "Yes\n";
    else cout << "No\n";
    

    return 0;
}
