#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int r = matrix.size();
        if (r == 0)
            return 0;
        int c = matrix[0].size();
        int res = 0;
        vector<int> height(c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    ++height[j];
            }
            res = max(res, findArea(height));
        }

        return res;
    }

    int findArea(vector<int> height) {
        int mx = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < height.size(); ++i) {
            int cur = height[i];
            if (st.empty() || cur >= height[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && cur < height[st.top()]) {
                    int temp = height[st.top()];
                    st.pop();
                    if (st.empty())
                        mx = max(mx, i * temp);
                    else
                        mx = max(mx, temp * (i - st.top() - 1));
                }
                st.push(i);
            }
        }
        if (!st.empty()) {
            while (!st.empty()) {
                int i = height.size();
                int temp = height[st.top()];
                st.pop();
                if (st.empty())
                    mx = max(mx, i * temp);
                else
                    mx = max(mx, temp * (i - st.top() - 1));
            }
        }
        return mx;
    }

};

int main() {
    vector<char> row1 = {'1','0','1','0','0'};
    vector<char> row2 = {'1','0','1','1','1'};
    vector<char> row3 = {'1','1','1','1','1'};
    vector<char> row4 = {'1','0','0','1','0'};
    vector<vector<char> > mat = {row1, row2, row3, row4};
    Solution* sol = new Solution();
    cout << sol->maximalRectangle(mat) << '\n';
    return 0;
}
