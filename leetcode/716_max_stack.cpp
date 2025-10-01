#include <bits/stdc++.h>

using namespace std;

class MaxStack {
public:
    MaxStack() {
        dl.clear();
        m.clear();
    }

    void push(int x) {
        dl.push_back(x);
        m[x].push_back(--dl.end());
    }

    int pop() {
        int x = top();
        dl.pop_back();
        m[x].pop_back();
        if (m[x].empty()) {
            m.erase(x);
        }
        return x;
    }

    int top() {
        return *dl.rbegin();
    }

    int peekMax() {
        return m.rbegin()->first;
    }

    int popMax() {
        int max = peekMax();
        auto iter = m[max].back();
        m[max].pop_back();
        if (m[max].empty()) {
            m.erase(max);
        }
        dl.erase(iter);
        return max;
    }
private:
    std::list<int> dl;
    std::map<int, std::vector<std::list<int>::iterator>> m;
};
