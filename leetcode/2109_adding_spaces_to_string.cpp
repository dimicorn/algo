#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length(), m = spaces.size();
        int i = 0, j = 0;
        string res = "";
        while (i < n && j < m) {
            if (i == spaces[j]) {
                res += ' ';
                ++j;
            }
            res += s[i];
            ++i;
        }
        while (i < n) {
            res += s[i];
            ++i;
        }
        return res;
    }
};


int main() {
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8,13,15}; 
    Solution* sol = new Solution();
    cout << sol->addSpaces(s, spaces) << '\n';
    return 0;
}
