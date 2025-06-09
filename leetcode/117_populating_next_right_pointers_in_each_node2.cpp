#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root;
        while (head != nullptr) {
            Node* dummy = new Node();
            Node* temp = dummy;
            while (head != nullptr) {
                if (head->left != nullptr) {
                    temp->next = head->left;
                    temp = temp->next;
                }
                if (head->right != nullptr) {
                    temp->next = head->right;
                    temp = temp->next;
                }
                head = head->next;
            }
            head = dummy->next;
        }
        return root;
    }
};
