#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        if (v[i].first == 1)
            cin >> v[i].second;
        else
            v[i].second = -1; 
    }   

    for (const auto &i : v) {
        if (i.first == 1)
            s.push(i.second);
        else
            s.pop();
    
        if (s.size() == 0)
            cout << "-1\n";
        else
            cout << s.top() << '\n';
    }   
    
    return 0;
}
