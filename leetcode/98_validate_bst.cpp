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
    bool isValidBST(TreeNode* root) {
        long long left = INT_MIN;
        long long right = INT_MAX;
        --left; ++right;
        return valid(root, left, right); 
    }

    bool valid(TreeNode* node, long long left, long long right) {
        if (node == nullptr)
            return true;
        if (!(node->val < right && node->val > left))
            return false;

        return valid(node->left, left, node->val) && valid(node->right, node->val, right);
    }
};

int main() {
    TreeNode* child_l = new TreeNode(1);
    TreeNode* child_r = new TreeNode(3);
    TreeNode* parent = new TreeNode(2, child_l, child_r);
    Solution* sol = new Solution();
    string res = (sol->isValidBST(parent)) ? "true" : "false";
    cout << res << '\n';

    return 0;
}
