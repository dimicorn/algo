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
    vector<int> res;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, "");
        int sum = 0;
        for (const auto& num : res) {
            cout << num << '\n';
            sum += num;
        }

        return sum;
    }

    void dfs(TreeNode* node, string num) {
        if (node == nullptr)
            return;
        if (node->left == nullptr && node->right == nullptr) {
            num += to_string(node->val);
            res.push_back(stoi(num));
            return;
        }

        num += to_string(node->val);
        dfs(node->left, num);
        dfs(node->right, num);
    }
};
