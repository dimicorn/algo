#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		unordered_set<char> alph;
		int count = 0;
		for (int i = 0; i < jewels.length(); ++i) {
			alph.insert(jewels[i]);
		}
		for (int i = 0; i < stones.length(); ++i) {
			if (alph.find(stones[i]) != alph.end()) {
				count++;
			}
		}
		return count;
	}
};

int main(int argc, char* argv[]) {
	string j1 = "aA";
	string s1 = "aAAbbbb";
	string j2 = "z";
	string s2 = "ZZ";

	Solution sol;
	cout << sol.numJewelsInStones(j1, s1) << '\n';
	cout << sol.numJewelsInStones(j2, s2) << '\n';
	return 0;
}
