#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>{};
        }
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp = {};
            int qLen = static_cast<int>(q.size());
            for (int i = 0; i < qLen; ++i) {
                auto node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};
