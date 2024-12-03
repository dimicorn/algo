#include <iostream>
#include <vector>
#include <numeric>       

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        auto gas_total = reduce(gas.begin(), gas.end());
        auto cost_total = reduce(cost.begin(), cost.end());
        if (cost_total > gas_total)
            return -1;

        int n = gas.size();
        int total = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            total += gas[i] - cost[i];

            if (total < 0) {
                start = i+1;
                total = 0;
            }
        }
        return start;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    cout << sol->canCompleteCircuit(gas, cost) << '\n';
    return 0;
}
