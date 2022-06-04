#include <iostream>
using namespace std;

//自动存储，静态存储， 动态存储
//

/*
自动存储：栈存储
函数形参，内部声明变量，结构体变量
*/
/*
int add(int m, int n)
{
	//z 
	int z = m + n;
	return z;
}

int add(int m, int n)
{
	if (m != 0)
	{
		//生命周期在代码块内
		int z = m + n;
	}
	//return z;
}*/
/*
静态存储：编译器预分配；永久存储
extern关键字，全局变量，外部变量 
定义性声明 和 引用性声明


*/


int main()
{
	//引用性声明
	extern int num1;
	cout << num1 << endl;
	//函数声明
	void change();

	change();
	cout << num1 << endl;

	system("pause");
	return 0;
}

int num1;

void change()
{
	num1 += 3;
}