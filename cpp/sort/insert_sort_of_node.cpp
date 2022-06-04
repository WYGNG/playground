#include <iostream>

using namespace std;


typedef struct node {
	int val;
	node* next;
} node;

void print(node * head) {
	while (head != nullptr) {
		cout << head->val << "->";
		head = head->next;
	}
	cout << endl;
}



int main() {

	node* head = nullptr, *create = nullptr, *pre = nullptr, *cur = nullptr;
	while (1) {
		print(head);
		create = (node *)malloc(sizeof(node));
		cin >> create->val;
		create->next = nullptr;
		if (head == nullptr) {
			head = create;
			continue;
		}
		cur = head;
		if (create->val < cur->val) {
			create->next = cur;
			head = create;
			continue;
		}
		while (create->val >= cur->val && cur->next != nullptr) {
			pre = cur;
			cur = cur->next;
		}
		if (create->val < cur->val) {
			pre->next = create;
			create->next = cur;
		}
		else {
			cur->next = create;
		}
	}

	system("pause");
	return 0;
}