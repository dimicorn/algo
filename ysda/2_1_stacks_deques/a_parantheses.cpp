#include <bits/stdc++.h>

using namespace std;

bool check(char ch, stack<char> st) {
    if (st.empty())
        return false;
    if (ch == ')' && st.top() == '(')
        return true;
    else if (ch == '}' && st.top() == '{')
        return true;
    else if (ch == ']' && st.top() == '[')
        return true;
    return false;
}

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (check(s[i], st)) {
                st.pop();
            } else {
                cout << "no\n";
                return 0;
            }
        }
    }
    if (st.empty())
        cout << "yes\n";
    else 
        cout << "no\n";
    return 0;
}
