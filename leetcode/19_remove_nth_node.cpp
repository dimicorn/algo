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
    int ListSize(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        while (curr != nullptr) {
            ++len;
            curr = curr->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = ListSize(head);
        if (sz == 1)
            return nullptr;
        else if (sz == n)
            return head->next;

        int count = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (count + n != sz) {
            prev = curr;
            curr = curr->next;
            ++count;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        curr->val = 0;
        return head;
    }
};

int main() {
    vector<int> nums = {2, 1};
    int n = 2;
    ListNode* head = new ListNode(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
        ListNode* node = new ListNode(nums[i], head);
        head = node;
    }

    Solution* sol = new Solution();
    ListNode* res = sol->removeNthFromEnd(head, n);
    while (res != nullptr) {
        cout << res->val << ' ';
        res = res->next;
    }
    cout << '\n';

    return 0;
}
