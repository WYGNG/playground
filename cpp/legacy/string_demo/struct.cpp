#include <iostream>
using namespace std;


struct ExS1
{
	char c1;//ƫ������1�ı���
	short s1;//2�ı���
	int i1;//4�ı���
};

struct ExS2
{
	//ƫ����ԭ��
	short s1;//2�ı���
	int i1;//4�ı���
	char c1;//ƫ������1�ı���
};

union Ex
{
	double x;
	char y;
};


int main()
{
	cout << sizeof(ExS1) << endl;//���Ϊ8
	cout << sizeof(ExS2) << endl;//���Ϊ12
	cout << sizeof(Ex) << endl;//���Ϊ8
	system("pause");
	return 0;
}