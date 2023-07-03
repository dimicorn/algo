#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class Solution {
public:
	bool dfs(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) {
			return true;
		}
		if (left == nullptr || right == nullptr) {
			return false;
		}
		return (left->val == right->val && dfs(left->left, right->right)
				&& dfs(left->right, right->left));
	}

	bool isSymmetric(TreeNode* root) {
		return dfs(root->left, root->right);	
	}
};

int main(int argc, char* argv[]) {
	// example 1 : root = [1, 2, 2, 3, 4, 4, 3]
	TreeNode* root1 = new TreeNode(1);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(2);
	root1->left->left = new TreeNode(3);
	root1->left->right = new TreeNode(4);
	root1->right->left = new TreeNode(4);
	root1->right->right = new TreeNode(3);

	// example 2 : root = [1, 2, 2, null, 3, null, 3];
	TreeNode* root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(2);
	root2->left->right = new TreeNode(3);
	root2->right->right = new TreeNode(3);

	Solution sol;
	if (sol.isSymmetric(root1)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	if (sol.isSymmetric(root2)) {
		cout << "true\n";
	} else {
		cout << "false\n";
	}

	return 0;
}

