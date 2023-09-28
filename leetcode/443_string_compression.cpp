#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		string s = "";
		int count = 1;
		s += chars[0];
		for (int i = 1; i < chars.size(); ++i) {
			if (chars[i] != chars[i-1] && count > 1) {
				s += to_string(count);
				count = 1;
				s += chars[i];
			} else if (chars[i] != chars[i-1] && count == 1) {
				s += chars[i];
			} else {
				++count;
			}
		}
		s += to_string(count);
		for (int i = 0; i < s.length(); ++i) {
			chars[i] = s[i];
		}

		return s.length();
	}
};

void print(vector<char>& v) {
	for (auto &it : v) {
		cout << it;
	}
	cout << '\n';
}

int main(int argc, char* argv[]) {
	vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	Solution sol;
	int ans = sol.compress(chars);
	print(chars);
	cout << ans << '\n';

	chars = {'a'};
	ans = sol.compress(chars);
	print(chars);
	cout << ans << '\n';

	chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
	ans = sol.compress(chars);
	print(chars);
	cout << ans << '\n';

	return 0;
}
