#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> st;
public:
    string simplifyPath(string path) {
        int n = path.length();
        path += '/';
        string cur = "";
        for (auto const &ch : path) {
            if (ch == '/') {
                if (cur == "..") {
                    if (!st.empty())
                        st.pop_back();
                } else if (cur != "" && cur != ".") {
                    st.push_back(cur);
                }
                cur = "";
            } else {
                cur += ch;
            }
        }
        if (st.empty())
            return "/";

        string res = "";
        for (auto const &it : st)
            res += "/" + it;
        return res;
    }
};

int main() {
    string path = "/home/";
    Solution* sol = new Solution();
    cout << sol->simplifyPath(path) << '\n';
    return 0;
}
