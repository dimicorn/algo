#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* next = nullptr;
        int add = 0;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* head = new ListNode((l1->val + l2->val + add) % 10, next);
            add = (l1->val + l2->val + add) / 10;
            next = head;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            ListNode* head = new ListNode((l1->val + add) % 10, next);
            add = (l1->val + add) / 10;
            next = head;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            ListNode* head = new ListNode((l2->val + add) % 10, next);
            add = (l2->val + add) / 10;
            next = head;
            l2 = l2->next;
        }

        if (add != 0) {
            ListNode* head = new ListNode(add % 10, next);
            next = head;
        }

        ListNode* res = reverseList(next);
        return res;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* forward = curr->next;

            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
};

int main() {
    vector<int> v1 = {7, 3}, v2 = {2, 9};
    ListNode* next = nullptr;
    for (auto const &i : v1) {
        ListNode* head = new ListNode(i, next);
        next = head;
    }

    ListNode* next2 = nullptr;
    for (auto const &i : v2) {
        ListNode* head = new ListNode(i, next2);
        next2 = head;
    }

    Solution* sol = new Solution();
    ListNode* res = sol->addTwoNumbers(next, next2);

    while (res != nullptr) {
        cout << res->val << ' ';
        res = res->next;
    }

    return 0;
}
