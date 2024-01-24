#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int ind = 0) {
        unordered_set<char> s(str.begin(), str.end());
        if (s.size() != str.length())
            return 0;

        int res = str.length();
        for (int i = ind; i < arr.size(); ++i)
            res = max(res, maxLength(arr, str+arr[i], i+1));

        return res;
    }
};

int main() {
    vector<string> arr = {"un","iq","ue"};
    Solution* sol = new Solution();
    cout << sol->maxLength(arr) << '\n';

    return 0;
}
