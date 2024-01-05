#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return sum;
        
        if (low <= root->val && root->val <= high) sum += root->val;
        rangeSumBST(root->left, low, high);
        rangeSumBST(root->right, low, high);
        return sum;
    }
private:
    int sum = 0;
};

int main() {
    TreeNode* child1 = new TreeNode(3);
    TreeNode* child2 = new TreeNode(7);
    TreeNode* child3 = new TreeNode(18);

    TreeNode* parent1 = new TreeNode(5, child1, child2);
    TreeNode* parent2 = new TreeNode(15, nullptr, child3);

    TreeNode* root = new TreeNode(10, parent1, parent2);

    Solution* sol = new Solution();
    cout << sol->rangeSumBST(root, 7, 15) << '\n';
    
    return 0;
}
