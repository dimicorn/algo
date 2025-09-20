#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> ends;
        int rooms = 1;
        for (const auto& interval : intervals) {
            if (ends.empty()) {
                ends.push_back(interval[1]);
                continue;
            }
            make_heap(ends.begin(), ends.end(), greater<>{});
            if (interval[0] < ends[0]) {
                ++rooms;
                ends.push_back(interval[1]);
            } else {
                pop_heap(ends.begin(), ends.end(), greater<>{});
                ends.pop_back();
                ends.push_back(interval[1]);
            }
        }
        return rooms;
    }
};
