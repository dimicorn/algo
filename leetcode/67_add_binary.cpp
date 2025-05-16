#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        if (m > n) {
            swap(a, b);
            swap(m, n);
        }
        string res = "";
        int carry = 0;
        int i = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            if (a[i] == '1' && b[j] == '0' || a[i] == '0' && b[j] == '1') {
                if (carry == 0)
                    res += "1";
                else 
                    res += "0";
            } else if (a[i] == '0' && b[j] == '0') {
                if (carry == 0)
                    res += "0";
                else
                    res += "1";
                carry = 0;
            } else {
                if (carry == 0)
                    res += "0";
                else
                    res += "1";
                carry = 1;
            }
            --i;
        }
        while (i >= 0) {
            if (carry == 0)
                res += a[i];
            else if (a[i] == '1')
                res += "0";
            else {
                res += "1";
                carry = 0;
            }
            --i;
        }
        if (carry == 1)
            res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string a = "11";
    string b = "1";
    auto sol = new Solution();
    cout << sol->addBinary(a, b) << '\n';

    return 0;
}
