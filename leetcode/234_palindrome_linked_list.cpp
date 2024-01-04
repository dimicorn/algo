#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        string orig_list = "", rev_list = "";
        while (curr != nullptr) {
            orig_list += to_string(curr->val);
            curr = curr->next;
        }

        ListNode* tail = reverseList(head);
        while (tail != nullptr) {
            rev_list += to_string(tail->val);
            tail = tail->next;
        }
        return orig_list == rev_list;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

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
    vector<int> v = {1, 2, 2, 1};
    ListNode* next = nullptr;
    for (auto const &i : v) {
        ListNode* head = new ListNode(i, next);
        next = head;
    }

    Solution* sol = new Solution();
    auto res = (sol->isPalindrome(next)) ? "true" : "false";
    cout << res << '\n';

    return 0;
}
