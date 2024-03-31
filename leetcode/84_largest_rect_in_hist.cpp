#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
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
    vector<int> heights = {2,1,5,6,2,3};
    Solution* sol = new Solution();
    cout << sol->largestRectangleArea(heights) << '\n';
    return 0;
}
