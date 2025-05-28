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
    int maxDepth(TreeNode* root) {
        int depth = dfs(root, 0); 
        return depth;
    }
    int dfs(TreeNode* node, int depth) {
        if (node == nullptr)
            return depth;
        ++depth;
        auto left = dfs(node->left, depth);
        auto right = dfs(node->right, depth);
        return max(left, right);
    }
};

int main() {
    auto tn = new TreeNode(2);
    auto root = new TreeNode(1, nullptr, tn);
    auto sol = new Solution();
    cout << sol->maxDepth(root) << '\n';

    return 0;
}
