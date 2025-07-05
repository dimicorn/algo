#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int cur = 0;
        int res = 0;
        int sign = 1;
        stack<int> st;
        for (const auto& c : s) {
            if (isdigit(c)) {
                cur = 10 * cur + (c - '0');
            } else if (c == '-' || c == '+') {
                res += sign * cur;
                sign = (c == '+') ? 1 : -1;
                cur = 0;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);

                sign = 1;
                res = 0;
            } else if (c == ')') {
                res += sign * cur;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
                cur = 0;
            }
        }
        return res + sign * cur;
    }
};

int main() {
    string s = "1 + 1";
    auto sol = new Solution();
    cout << sol->calculate(s) << '\n';
    return 0;
}
