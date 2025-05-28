#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }

bool dfs(TreeNode* node, int targetSum, int temp) {
        if (node == nullptr)
            return false;

        temp += node->val;

        if (node->left == nullptr && node->right == nullptr)
            return temp == targetSum;

        return dfs(node->left, targetSum, temp) ||
               dfs(node->right, targetSum, temp);
    }

};
