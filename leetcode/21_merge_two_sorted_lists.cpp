#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void print(ListNode* list) {
	while (list != nullptr) {
		cout << list->val << ' ';
		list = list->next;
	}
	cout << '\n';
}

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode dummy(-1);
		ListNode* ans = &dummy;
		
		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val) {
				ans->next = list1;
				list1 = list1->next;
			} else {
				ans->next = list2;
				list2 = list2->next;
			}
			ans = ans->next;
		}
		if (list1 != nullptr) {
			ans->next = list1;
		} else {
			ans->next = list2;
		}
		return dummy.next;
	}
};

int main(int argc, char* argv[]) {
	ListNode* list1 = new ListNode(1);
	list1->next = new ListNode(2);
	list1->next->next = new ListNode(4);
	ListNode* list2 = new ListNode(1);
	list2->next = new ListNode(3);
	list2->next->next = new ListNode(4);

	Solution sol;
	ListNode* ans = sol.mergeTwoLists(list1, list2);
	print(ans);

	list1 = nullptr;
	list2 = nullptr;

	ans = sol.mergeTwoLists(list1, list2);
	print(ans);

	ListNode* list3 = new ListNode();

	ans = sol.mergeTwoLists(list3, list2);
	print(ans);

	return 0;
}
