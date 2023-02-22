#include <bits/stdc++.h>

using namespace std;

int str2time (string x) {
    string temp = "";
    int res = 0;
    for (int i = 0; i < x.length(); ++i) {
        if (x[i] == ':') {
            if (i == 2) {
                res += stoi(temp) * 3600;
            } else if (i == 5) {
                res += stoi(temp) * 60;
            } else {
                res += stoi(temp);
            }
            temp = "";
        } else {
            temp += x[i];
        }
    }
    return res;
}

string time2str(int x) {
    string res = "";
    x %= 24 * 3600;
    if (x / 3600 < 10) {
        res += '0';
    }
    res += to_string(x / 3600);
    res += ':';
    x %= 3600;
    if (x / 60 < 10) {
        res += '0';
    }
    res += to_string(x / 60);
    res += ':';
    x %= 60;
    if (x < 10) {
        res += '0';
    }
    res += to_string(x);
    return res;
}

int main() {
    string a, b, c;
    int res;
    float time[3];
    cin >> a >> b >> c;
    a += ':';
    b += ':';
    c += ':';
    time[0] = str2time(a);
    time[1] = str2time(b);
    time[2] = str2time(c);
    
    if (time[2] > time[0]) {
        res = time[1] + round((time[2] - time[0]) / 2);
    } else {
        time[2] += 24 * 3600;
        res = time[1] + round((time[2] - time[0]) / 2);
    }
    cout << time2str(res) << '\n';
    return 0;
}