#include <iostream>
using namespace std;


struct ExS1
{
	char c1;//偏移量是1的倍数
	short s1;//2的倍数
	int i1;//4的倍数
};

struct ExS2
{
	//偏移量原理
	short s1;//2的倍数
	int i1;//4的倍数
	char c1;//偏移量是1的倍数
};

union Ex
{
	double x;
	char y;
};


int main()
{
	cout << sizeof(ExS1) << endl;//输出为8
	cout << sizeof(ExS2) << endl;//输出为12
	cout << sizeof(Ex) << endl;//输出为8
	system("pause");
	return 0;
}