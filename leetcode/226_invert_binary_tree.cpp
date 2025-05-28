#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }   

    TreeNode* dfs(TreeNode* node) {
        if (node == nullptr)
            return nullptr;
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        return new TreeNode(node->val, right, left);
    }   
};

int main() {
    auto tn = new TreeNode(1);
    auto tn2 = new TreeNode(3);
    auto root = new TreeNode(2, tn, tn2);
    auto sol = new Solution();

    return 0;
}
