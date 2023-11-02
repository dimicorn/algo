#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<char> s;
    string brackets;
    cin >> brackets;

    for (const auto &b : brackets) {
        if (b == '(' || b == '{' || b == '[') {
            s.push(b);
        } else if (b == ')') {
            if (s.empty()) {
                cout << "no\n";
                return 0;
            }
            if (s.top() != '(') {
                cout << "no\n";
                return 0;
            } else s.pop();
        } else if (b == '}') {
            if (s.empty()) {
                cout << "no\n";
                return 0;
            }
            if (s.top() != '{') {
                cout << "no\n";
                return 0;
            } else s.pop();
        } else if (b == ']') {
            if (s.empty()) {
                cout << "no\n";
                return 0;
            }
            if (s.top() != '[') {
                cout << "no\n";
                return 0;
            } else s.pop();
        }
    }

    if (s.empty()) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    
    return 0;
}
