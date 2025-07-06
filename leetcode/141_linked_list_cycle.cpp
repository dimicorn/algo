#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        auto tort = head;
        auto hare = head->next;
        while (tort != hare && hare != nullptr) {
            tort = tort->next;
            hare = hare->next;
            if (hare == nullptr)
                return false;
            hare = hare->next;
        }
        return tort == hare;
    }
};
