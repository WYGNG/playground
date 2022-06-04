#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


//int main() {
//	vector<string> rawString;
//	string tempString;
//	//for (int i = 0; i < 4; i++) {
//	//	cin >> tempString;
//	//	rawString.push_back(tempString);
//	//}
//	while (cin >> tempString) {
//		rawString.push_back(tempString);
//	}
//	map<int, int> mp;
//	for (auto s : rawString) {
//		string temp;
//		for (auto c : s) {
//			if (c >= '0' && c <= '9') {
//				temp += c;
//			}
//			else {
//				mp[stoi(temp)]++;
//				temp.clear();
//			}
//		}
//		if (!temp.empty()) {
//			mp[stoi(temp)]++;
//			temp.clear();
//		}
//	}
//
//	int ret = -1;
//	for (auto item : mp) {
//		if (item.second == rawString.size()) {
//			ret = item.first;
//			break;
//		}
//	}
//	cout << ret << endl;
//	//system("pause");
//	return 0;
//}

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void reorderList(ListNode* head) {
	if (!head) return;
	vector<ListNode*> vec;
	ListNode* cur = head;

	while (cur) {
		vec.push_back(cur);
		cur = cur->next;
	}

	int left = 0;
	int right = vec.size() - 1;
	while (left < right) {
		vec[left]->next = vec[right];
		vec[right--]->next = vec[++left];
	}
	vec[left]->next = nullptr;
}

void printList(ListNode* head) {
	while (head->next) {
		cout << head->val << ',';
		head = head->next;
	}
	cout << head->val << endl;
}

int main() {
	string rawString;
	cin >> rawString;

	ListNode* dummy = new ListNode(0);
	ListNode* tail = dummy;

	string temp;
	for (auto c : rawString) {
		if (c >= '0' && c <= '9') {
			temp += c;
		}
		else {
			tail->next = new ListNode(stoi(temp));
			tail = tail->next;
			temp.clear();
		}
	}
	if (!temp.empty()) {
		tail->next = new ListNode(stoi(temp));
		tail = tail->next;
		tail->next = nullptr;
		temp.clear();
	}


	reorderList(dummy->next);
	printList(dummy->next);

	//system("pause");
	return 0;
}