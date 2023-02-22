#include <bits/stdc++.h>

using namespace std;

vector<double> solve(vector<double> res, double a, double b, double c, double d, double e, double f) {
    double det = a * d - c * b;
    double coef, x, y;
    if (det == 0) {
        if (a == 0 && c == 0) {
            if (b == 0 && d == 0) {
                if (e == 0 && f == 0) {
                    res.push_back(5);
                    return res;
                }
                res.push_back(0);
                return res;
            }
            if (e * d != f * b) {
                res.push_back(0);
                return res;
            } else if (b != 0) {
                res.push_back(4);
                res.push_back(e / b);
                return res;
            } else {
                res.push_back(4);
                res.push_back(f / d);
                return res;
            }
        }
        if (b == 0 && d == 0) {
            if (e * c != f * a) {
                res.push_back(0);
                return res;
            } else if (a != 0) {
                res.push_back(3);
                res.push_back(e / a);
                return res;
            } else {
                res.push_back(3);
                res.push_back(f / c);
                return res;
            }
        }
        if (a != 0) {
            coef = c / a;
            c = 0;
            d -= coef * b;
            f -= coef * e;
            if (c == 0 && d == 0 && f == 0) {
                res.push_back(1);
                res.push_back(-a / b);
                res.push_back(e / b);
                return res;
            }
        } else {
            coef = a / c;
            a = 0;
            b -= coef * d;
            e -= coef * f;
            if (a == 0 && b == 0 && e == 0) {
                res.push_back(1);
                res.push_back(-c / d);
                res.push_back(f / d);
                return res;
            }
        }
        res.push_back(0);
        return res;
    } else if (d != 0) {
        x = (e - b * f / d) / (a - b * c / d);
        y = (f - c * x) / d;
        res.push_back(2);
        res.push_back(x);
        res.push_back(y);
        return res;
    } else {
        x = (f - d * e / b) / (c - d * a / b);
        y = (e - a * x) / b;
        res.push_back(2);
        res.push_back(x);
        res.push_back(y);
        return res;
    }
}

void print(vector<double> arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
int main(int argc, char* argv[]) {
    double a, b, c, d, e, f;
    vector<double> res;
    cin >> a >> b >> c >> d >> e >> f;
    res = solve(res, a, b, c, d, e, f);

    if (res[0] == 0) {
        print(res, 1);
    } else if (res[0] == 1) {
        print(res, 3);
    } else if (res[0] == 2) {
        print(res, 3);
    } else if (res[0] == 3) {
        print(res, 2);
    } else if (res[0] == 4) {
        print(res, 2);
    } else if (res[0] == 5) {
        print(res, 1);
    }

    return 0;
}

