#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int min_dif = INT_MAX;
        for (int i = 1; i < nums.size(); ++i)
            min_dif = min(min_dif, abs(nums[i] - nums[i-1]));
        return min_dif;
    }

    void dfs(TreeNode* node) {
        if (node == nullptr)
            return;
        dfs(node->left);
        nums.push_back(node->val);
        dfs(node->right);
    }
private:
    vector<int> nums;
};
