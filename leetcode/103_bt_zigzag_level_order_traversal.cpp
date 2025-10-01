#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>{};
        }
        vector<vector<int>> result;
        deque<TreeNode*> q;
        q.push_back(root);
        int count = 0;
        while (!q.empty()) {
            vector<int> tmp = {};
            auto qLen = static_cast<int>(q.size());
            if (count % 2 == 0) {
                for (int i = 0; i < qLen; ++i) {
                    auto node = q.front();
                    q.pop_front();
                    tmp.push_back(node->val);
                    if (node->left != nullptr) {
                        q.push_back(node->left);
                    }
                    if (node->right != nullptr) {
                        q.push_back(node->right);
                    }
                }
            } else {
                for (int i = 0; i < qLen; ++i) {
                    auto node = q.back();
                    q.pop_back();
                    tmp.push_back(node->val);
                    if (node->right != nullptr) {
                        q.push_front(node->right);
                    }
                    if (node->left != nullptr) {
                        q.push_front(node->left);
                    }

                }
            }
            result.push_back(tmp);
            ++count;
        }
        return result;
    }
};
