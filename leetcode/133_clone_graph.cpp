#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> seen;
        Node* root = new Node(node->val);
        seen[node] = root;
        vector<Node*> st;
        st.push_back(node);

        while (!st.empty()) {
            auto cur = st.back();
            st.pop_back();

            Node* copy = seen[cur];
            for (const auto& n: cur->neighbors) {
                if (seen.find(n) == seen.end()) {
                    seen[n] = new Node(n->val);
                    st.push_back(n);
                }
                copy->neighbors.push_back(seen[n]);
            }
        }
        return root;
    }
};
