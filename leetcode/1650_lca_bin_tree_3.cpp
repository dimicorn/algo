#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        Node* a = p;
        Node* b = q;

        while (a != b) {
            a = a ? a->parent : q;
            b = b ? b->parent : p;
        }

        return b;
    }
};
