#include <iostream>
#include "pch.h"
#define NULL 0
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode*fast = pHead, *low = pHead;
		while (fast&&fast->next) {
			fast = fast->next->next;
			low = low->next;
			if (fast == low)
				break;
		}
		if (!fast || !fast->next)return NULL;
		low = pHead;//low从链表头出发
		while (fast != low) {//fast从相遇点出发
			fast = fast->next;
			low = low->next;
		}
		return low;
	}
};

int main() {
	Solution A;
	return 0;
}