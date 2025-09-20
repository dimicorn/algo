#include <bits/stdc++.h>

using namespace std;

class HitCounter {
public:
    HitCounter() {
    }

    void hit(int timestamp) {
        q.push_back(timestamp);
    }

    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front() >= 300) {
            q.pop_front();
        }
        return q.size();
    }
private:
    deque<int> q;
};
