#include <bits/stdc++.h>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        calls = {};
    }

    int ping(int t) {
        calls.push_back(t);
        int f = calls.front();
        while (t - f > 3000) {
            calls.pop_front();
            f = calls.front();
        }
        
        return calls.size();
    }
private:
deque<int> calls;
};

int main() {
    RecentCounter* obj = new RecentCounter();
    int param_1 = obj->ping(1);
    cout << param_1 << '\n';

    return 0;
}
