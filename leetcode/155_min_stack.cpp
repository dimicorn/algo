#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(make_pair(val, val));
        } else {
            auto tmp = st.top();
            st.push(make_pair(val, min(val, tmp.second)));
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
};
