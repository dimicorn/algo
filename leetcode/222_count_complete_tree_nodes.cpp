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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left_level = 1;
        auto l = root->left;
        while (l != nullptr) {
            l = l->left;
            ++left_level;
        }

        int right_level = 1;
        auto r = root->right;
        while (r != nullptr) {
            r = r->right;
            ++right_level;
        }
        if (left_level == right_level)
            return pow(2, left_level) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
