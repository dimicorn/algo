#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>>& v) {
	for (auto &i : v) {
		cout << '[' << i[0] << ',' << i[1] << "]\t";
	}
	cout << '\n';
}

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [] (auto const &x, auto const &y) {return x[0] < y[0];});
		vector<vector<int>> ans;
		ans.push_back(intervals[0]);
		if (intervals.size() == 1) {
			return ans;
		}
		for (int i = 1; i < intervals.size(); ++i) {
			if (ans[ans.size()-1][1] >= intervals[i][0] && ans[ans.size()-1][1] >= intervals[i][1]) {
				continue;
			} else if (ans[ans.size()-1][1] >= intervals[i][0]) {
				ans[ans.size()-1][1] = intervals[i][1];
			} else {
				ans.push_back(intervals[i]);
			}
		}
		return ans;
	}
};

int main(int argc, char* argv[]) {
	vector<vector<int>> ints = {{1,3},{2,6},{8,10},{15,18}};
	Solution sol;
	vector<vector<int>> ans = sol.merge(ints);
	print(ints);
	print(ans);

	ints = {{1,4},{4,5}};
	ans = sol.merge(ints);
	print(ints);
	print(ans);

	return 0;
}
