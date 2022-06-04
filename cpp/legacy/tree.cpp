#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;
public:
	Node() : data(-1), parent(nullptr), left(nullptr), right(nullptr) {};
	Node(int num) : data(num), parent(nullptr), left(nullptr), right(nullptr) {};
};

class Tree
{
public:
	Tree(int num[], int len);
	void insertNode1(int data);	//递归方法
	void insertNode(int data);	//非递归方法
	Node *searchNode(int data);
	void deleteNode(int data);

private:
	void insertNode(Node* cur, int data);
	Node* searchNode(Node* cur, int data);
	void deleteNode(Node* cur);

private:
	Node* root;
};

Tree::Tree(int num[], int len) {
	root = new Node(num[0]);
	for (int i = 1; i < len; i++) {
		insertNode(num[i]);
	}
}

void Tree::insertNode1(int data) {
	Node* p, *par;
	Node* newNode = new Node(data);

	p = par = root;

	while (p) {
		par = p;
		if (data > p->data) {
			p = p->right;
		}
		else if (data < p->data) {
			p = p->left;
		}
		else {
			delete newNode;
			return;
		}
	}
	newNode->parent = par;
	if (par->data > newNode->data) {
		par->left = newNode;
	}
	else {
		par->right = newNode;
	}
}



int main() {



























	system("pause");
	return 0;
}