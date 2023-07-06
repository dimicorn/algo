#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, c, d;
	pair<int, int> p;
    cin >> n >> m;
	vector<pair<int, int>> teachers(m);
	vector<pair<int, int>> ans;
	for (int i = 0; i < m; ++i) {
		cin >> p.first >> p.second;
		teachers[i] = p;
	}
	sort(teachers.begin(), teachers.end(), [](auto const &x, auto const &y) {return x.first < y.first;});
	ans.push_back(teachers[0]);
	for (int i = 1; i < m; ++i) {
		if (ans[ans.size()-1].second >= teachers[i].first && ans[ans.size()-1].second >= teachers[i].second) {
			continue;
		} else if (ans[ans.size()-1].second >= teachers[i].first) {
			ans[ans.size()-1].second = teachers[i].second;
		} else {
			ans.push_back(teachers[i]);
		}
	}
	int students = n;
	for (int i = 0; i < ans.size(); ++i) {
		students -= ans[i].second - ans[i].first + 1;
	}
	cout << students << '\n';
    return 0;
}
