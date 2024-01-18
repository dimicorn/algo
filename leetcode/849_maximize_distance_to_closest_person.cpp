#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int dist = 0;
        bool seen = false;
        int l = 0, r = 0;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 0 && not seen) {
                l = i;
                seen = true;
            } else if (seats[i] == 1 && seen) {
                if (l == 0)
                    dist = max(dist, i);
                else
                    dist = max(dist, static_cast<int>(floor((i - l + 1) / 2.0)));
                seen = false;
            } else if (i == seats.size()-1 && seen) {
                dist = max(dist, i - l + 1);
                seen = false;
            }
        }
        return dist;
    }
};

int main() {
    vector<int> seats = {0,1};
    Solution* sol = new Solution();
    cout << sol->maxDistToClosest(seats) << '\n';

    return 0;
}
