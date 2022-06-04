#include <iostream>

using namespace std;



struct LinkListNode {
	struct LinkListNode * next;
	int val;
};

LinkListNode* findMidNode(LinkListNode* head);

int main() {







	system("pause");
	return 0;
}



LinkListNode* findMidNode(LinkListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	LinkListNode* fast = head;
	LinkListNode* slow = head;
	while (fast != nullptr) {
		fast = fast->next;
		if (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow;
}