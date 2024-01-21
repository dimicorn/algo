#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return split(lists, 0, lists.size()-1);
    }

    ListNode* split(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];

        int mid = (start + end) / 2;
        ListNode* left = split(lists, start, mid);
        ListNode* right = split(lists, mid+1, end);
        return merge(left, right);
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                dummyTail->next = head1;
                head1 = head1->next;
            } else {
                dummyTail->next = head2;
                head2 = head2->next;
            }
            dummyTail = dummyTail->next;
        }
        dummyTail->next = (head1 != nullptr) ? head1 : head2;

        return dummyHead->next;
    }

};

ListNode* create_list(vector<int> &v) {
    ListNode* head = new ListNode(v[0]);
    for (int i = 1; i < v.size(); ++i) {
        ListNode* tmp = new ListNode(v[i], head);
        head = tmp;
    }
    return head;
}

void print(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}

int main() {
    vector<int> v1 = {5,4,1}, v2 = {4,3,1}, v3 = {6,2};
    vector<ListNode*> lists = {};
    lists.push_back(create_list(v1));
    lists.push_back(create_list(v2));
    lists.push_back(create_list(v3));

    Solution* sol = new Solution();
    ListNode* res = sol->mergeKLists(lists);
    print(res);

    return 0;
}
