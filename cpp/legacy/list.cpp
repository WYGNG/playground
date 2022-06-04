#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

#include <>

using namespace std;

////通用链表节点抽象
//typedef struct LinkTableNode {
//	struct LinkTableNode *pNext;
//} tLinkListNode;
//
////定义链表
//typedef struct LinkTable {
//	tLinkListNode *pHead;
//	tLinkListNode *pTail;
//	int SumOfNode;
//} tLinkList;
//
////定义菜单结构体
//typedef struct DataNode {
//	struct DataNode *pNext;
//	const char* cmd;
//	const char* desc;
//	int(*handler)();
//} tMenuDataNode;
//
//static tMenuDataNode menu[] = {
//	{(tLinkListNode *)&menu[0], "time", "this is time cmd!"},
//	{(tLinkListNode *)&menu[1], "version", "this is version cmd!"},
//	{(tLinkListNode *)&menu[2], "help", "this is help cmd!"},
//	{(tLinkListNode *)&menu[3], "add", "this is add cmd!"},
//	{(tLinkListNode *)&menu[4], "sub", "this is sub cmd!"},
//	{(tLinkListNode *)&menu[5], "mul", "this is mul cmd!"},
//	{(tLinkListNode *)&menu[6], "div", "this is div cmd!"},
//	{(tLinkListNode *)&menu[7], "pow", "this is pow cmd!"},
//};
//
//tLinkList * CreateLinkTable() {
//	tLinkList * head = (tLinkList *)malloc(sizeof(tLinkList));
//	tLinkList * origin = head;
//
//	head->pHead = (tLinkListNode *)malloc(sizeof(tLinkListNode));
//	int conut = 8;
//	for (int i = 0; i < 8; i++) {
//		tLinkList * node = (tLinkList *)malloc(sizeof(tLinkList));
//		node->pHead = (tLinkListNode *)malloc(sizeof(tLinkListNode));
//		head->pHead = (tLinkListNode *)&menu[i];
//		head->pHead->pNext = node->pHead;
//		head = node;
//	}
//	return origin;
//}

//原则1 每个元素起始地址是自身长度整数倍
//原则2 结构体最后长度是最大长度整数倍
//原则3 强制对齐其地址是自身和pack参数中的较小值
//原则4	注意就算完成原则3还要完成原则2
//#pragma pack(4)
struct abs {
	volatile int a:1;
	volatile char b:1;
	volatile int c:2;
};

int main() {
	//const char * const p = "abd";
	
	struct abs hello;
	const struct abs * absptr = &hello;
	cout << static_cast<int>(sizeof(hello)) << endl;
	cout << const_cast<struct abs *>(absptr) << endl;
	default_delete<int> gh;
	unique_ptr<int> uptr;
	shared_ptr<int> git;
	
	auto_ptr<int> autoptr;

	

	system("pause");
	return 0;
}



