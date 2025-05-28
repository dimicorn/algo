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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return nullptr;
        auto mid = 0;
        while (inorder[mid] != postorder[postorder.size() - 1])
            ++mid;

        vector<int> inorder_left(inorder.begin(), inorder.begin() + mid);
        vector<int> inorder_right(inorder.begin() + mid + 1, inorder.end());
        vector<int> postorder_left(postorder.begin(), postorder.begin() + mid);
        vector<int> postorder_right(postorder.begin() + mid, postorder.end() - 1);
        auto root = new TreeNode(
            postorder[postorder.size() - 1],
            buildTree(inorder_left, postorder_left),
            buildTree(inorder_right, postorder_right)
        );
        return root;
    }
};
