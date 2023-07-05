#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		int a, b;
		for (int i = 0; i < tokens.size(); ++i) {
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				if (tokens[i] == "+") {
					s.push(b + a);
				} else if (tokens[i] == "-") {
					s.push(b - a);
				} else if (tokens[i] == "*") {
					s.push(b * a);
				} else if (tokens[i] == "/") {
					s.push(b / a);
				}
			} else {
				s.push(stoi(tokens[i]));
			}
		}
		return s.top();
	}
};

int main(int argc, char* argv[]) {
	vector<string> tokens = {"2","1","+","3","*"};
	Solution sol;
	cout << sol.evalRPN(tokens) << '\n';

	tokens = {"4","13","5","/","+"};
	cout << sol.evalRPN(tokens) << '\n';

	tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout << sol.evalRPN(tokens) << '\n';

	return 0;
}
