#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<char> buf;
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n); 
        return res;
    }
    void backtrack(int open_n, int closed_n, int n) {
        if (open_n == closed_n && open_n == n) {
            string str = "";
            for (auto const &it : buf)
                str += it;
            res.push_back(str);
            return;
        }
        if (open_n < n) {
            buf.push_back('(');
            backtrack(open_n+1, closed_n, n);
            buf.pop_back();
        }
        if (closed_n < open_n) {
            buf.push_back(')');
            backtrack(open_n, closed_n+1, n);
            buf.pop_back();
        }
    }
};

int main() {
    int n = 3;
    Solution* sol = new Solution();
    vector<string> ans = sol->generateParenthesis(n);
    for (auto const &it : ans)
        cout << it << '\n';

    return 0;
}
