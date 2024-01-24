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
    int odd = 0;
    unordered_map<int, int> freq;
    int pseudoPalindromicPaths(TreeNode* root) {
        return dfs(root);
    }
    
    int dfs(TreeNode* node) {
        int res;
        if (node == nullptr)
            return 0;

        if (freq.find(node->val) == freq.end())
            freq[node->val] = 1;
        else
            ++freq[node->val];
        int odd_change = (freq[node->val] % 2 == 1) ? 1 : -1;
        odd += odd_change;
        
        if (node->left == nullptr && node->right == nullptr)
            res = (odd <= 1) ? 1 : 0;
        else
            res = dfs(node->left) + dfs(node->right);
        odd -= odd_change;
        --freq[node->val];
        return res;
    }
};

int main() {
    TreeNode* child1 = new TreeNode(3);
    TreeNode* child2 = new TreeNode(1);
    TreeNode* child3 = new TreeNode(1);
    TreeNode* parent1 = new TreeNode(3, child1, child2);
    TreeNode* parent2 = new TreeNode(1, nullptr, child3);
    TreeNode* root = new TreeNode(2, parent1, parent2);

    Solution* sol = new Solution();
    cout << sol->pseudoPalindromicPaths(root) << '\n';

    return 0;
}
