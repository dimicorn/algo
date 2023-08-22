#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int min = prices[0];
		int profit = 0;
		for (int i = 1; i < n; ++i) {
			if (prices[i] < min) {
				min = prices[i];
			} else if (prices[i] - min > profit) {
				profit = prices[i] - min;
			}
		}

		return profit;
	}
};

int main() {
	Solution sol;
	vector<int> prices = {7,1,5,3,6,4};
	cout << sol.maxProfit(prices) << '\n';
	prices = {7,6,4,3,1};
	cout << sol.maxProfit(prices) << '\n';

	return 0;
}
