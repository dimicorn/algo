#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* rightSide = nullptr;
            auto qLen = static_cast<int>(q.size());
            for (int i = 0; i < qLen; ++i) {
                auto node = q.front();
                q.pop();
                if (node != nullptr) {
                    rightSide = node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (rightSide != nullptr) {
                result.push_back(rightSide->val);
            }

        }
        return result;
    }


};
