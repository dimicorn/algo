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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        auto mid = 0;
        while (inorder[mid] != preorder[0])
            ++mid;
        
        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> preorder_right(preorder.begin() + mid + 1, preorder.end());
        vector<int> inorder_left(inorder.begin(), inorder.begin() + mid);
        vector<int> inorder_right(inorder.begin() + mid + 1, inorder.end());
        
        auto root = new TreeNode(preorder[0], 
            buildTree(preorder_left, inorder_left),
            buildTree(preorder_right, inorder_right)
        );
        return root;
    }
};
