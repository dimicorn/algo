#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int main() {
    const string TOP = "top", BOTTOM = "bottom";
    string surname, location;
    int n, m;
    cin >> n;
    deque<string> papers;
    vector<string> v;
    
    for (int i = 0; i < n; ++i) {
        cin >> surname >> location;
        if (location == TOP)
            papers.push_front(surname);
        else if (location == BOTTOM)
            papers.push_back(surname);
    }
    for (const auto &i : papers)
        v.push_back(i);
    cin >> m;
    vector<int> q(m);
    for (int i = 0; i < m; ++i)
        cin >> q[i];
    for (const auto &i: q)
        cout << v[i-1] << '\n';

    return 0;
}
