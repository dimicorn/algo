#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    double a;
    vector<double> v;
    while (cin >> a && a != EOF) {
        v.push_back(a);
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        printf("%.4f\n", sqrt(v[i]));
    }
    return 0;
}

