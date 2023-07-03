#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isMatching(char s1, char s2) {
		if (s1 == '(' && s2 == ')') {
			return true;
		} else if (s1 == '{' && s2 == '}') {
			return true;
		} else if (s1 == '[' && s2 == ']') {
			return true;
		} else {
			return false;
		}
	}

	bool isValid(string s) {
		stack<char> st;
		int n = s.length();
		if (n % 2 != 0) {
			return false;
		}

		for (int i = 0; i < n; ++i) {
			if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
				st.push(s[i]);
			} else {
				if (st.empty()) {
					return false;
				} else if (isMatching(st.top(), s[i])) {
					st.pop();
				} else {
					return false;
				}
			}
		}
		if (st.empty()) {
			return true;
		} else {
			return false;
		}
	}
};

int main(int argc, char* argv[]) {
	string s1 = "()";
	string s2 = "()[]{}";
	string s3 = "(]";
	
	Solution sol;

	if (sol.isValid(s1)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	if (sol.isValid(s2)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	if (sol.isValid(s3)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	return 0;
}
