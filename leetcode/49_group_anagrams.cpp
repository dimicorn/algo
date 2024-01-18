#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res = {};
        for (auto const &str : strs) {
            string strSorted = str;
            sort(strSorted.begin(), strSorted.end());
            if (map.find(strSorted) == map.end())
                map[strSorted] = {str};
            else
                map[strSorted].push_back(str);
        }
        for (auto const &v : map) {
            vector<string> tmp = {};
            for (auto const &str : v.second)
                tmp.push_back(str);
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution* sol = new Solution();
    vector<vector<string>> res = sol->groupAnagrams(strs);
    for (auto const &v: res) {
        cout << "[ ";
        for (auto const &str : v)
            cout << str << ' ';
        cout << ']';
    }
    cout << '\n';

    return 0;
}
