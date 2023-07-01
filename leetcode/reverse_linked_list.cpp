#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void push(int x, ListNode **head) {
	ListNode* new_node = new ListNode(x, *head);
	(*head) = new_node;
}

void print(ListNode* head) {
	while (head != nullptr) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << '\n';
}

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		ListNode* next = nullptr;
		while (curr != nullptr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
		return head;
	}
};

int main(int argc, char* argv[]) {
	// example 1: head = [1, 2, 3, 4, 5]
	
	ListNode* head1 = nullptr;
	for (int i = 5; i >= 1; --i) {
		push(i, &head1);
	}

	ListNode* head2 = nullptr;
	push(2, &head2);
	push(1, &head2);

	ListNode* head3 = nullptr;

	Solution sol;

	print(head1);
	ListNode* ans1 = sol.reverseList(head1);
	print(ans1);

	print(head2);
	ListNode* ans2 = sol.reverseList(head2);
	print(ans2);

	print(head3);
	ListNode* ans3 = sol.reverseList(head3);
	print(ans3);

	return 0;
}
