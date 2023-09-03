#include <bits/stdc++.h>

using namespace std;

struct candidate {
	string party;
	int votes;
};

int main() {
	int n, m;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	unordered_map<string, candidate> cands;
	string name, party;
	for (int i = 0; i < n; ++i) {
		getline(cin, name);
		getline(cin, party);
		cands[name].party = party;
		cands[name].votes = 0;
	}
	cin >> m;
	getline(cin, name);
	for (int i = 0; i < m; ++i) {
		getline(cin, name);
		if (cands.find(name) != cands.end()) {
			cands[name].votes++;
		}
	}
	int max_votes = 0;
	string max_party = "n/a";

	for (auto &it : cands) {
		auto temp = it.second;
		if (temp.votes > max_votes) {
			max_votes = temp.votes;
			max_party = temp.party;
		} else if (temp.votes == max_votes) {
			max_party = "tie";
		}
	}

	cout << max_party << '\n';

	return 0;
}
