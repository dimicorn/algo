#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int res = root->val;
        vector<pair<TreeNode*, bool>> st;
        st.push_back(make_pair(root, false));
        unordered_map<TreeNode*, int> gains;

        while (!st.empty()) {
            auto [node, visited] = st.back();
            st.pop_back();

            if (node == nullptr) {
                continue;
            }
            if (visited) {
                auto leftMax = max(gains.find(node->left) == gains.end() ? 0 : gains.at(node->left), 0);
                auto rightMax = max(gains.find(node->right) == gains.end() ? 0 : gains.at(node->right), 0);
                res = max(res, node->val + leftMax + rightMax);
                gains[node] = node->val + max(leftMax, rightMax);
            } else {
                st.push_back(make_pair(node, true));
                st.push_back(make_pair(node->right, false));
                st.push_back(make_pair(node->left, false));
            }
        }
        return res;
    }
};
