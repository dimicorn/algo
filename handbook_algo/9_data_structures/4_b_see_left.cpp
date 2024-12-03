#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), res(n);
    stack<pair<int, int> > st;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    st.push(make_pair(INT_MAX, -1));
    for (int i = 0; i < n; ++i) {
        while (st.top().first < v[i])
            st.pop();
        res[i] = i - st.top().second - 1;
        st.push(make_pair(v[i], i));
    }
    
    for (const auto &i: res)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
