#include <bits/stdc++.h>

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode* root): index(-1) {
        result = inorderTraversal(root);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> st;
        auto* cur = root;

        while (cur != nullptr || !st.empty()) {
            while (cur != nullptr) {
                st.push_back(cur);
                cur = cur->left;
            }

            cur = st.back();
            st.pop_back();
            result.push_back(cur->val);
            cur = cur->right;
        }
        return result;
    }
    int next() {
        ++index;
        return result[index];
    }

    bool hasNext() {
        return index < static_cast<int>(result.size()) - 1;
    }
private:
    int index;
    vector<int> result;
};
