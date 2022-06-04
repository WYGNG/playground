#include <iostream>
using namespace std;

//函数模板
//显示实例化
//隐式实例化

//函数模板的声明
template<class Ex>
Ex Greater(Ex x, Ex y);
//显示实例化
template int Greater<int>(int, int);
int main()
{
	int intX = 1, intY = 2;
	double dblX = 3.0, dblY = 2.9;
	//隐式实例化
	//实参为int，生成int型模板函数，并对第二个参数检查
	cout << Greater(intX, intY) << endl;
	cout << Greater(dblX, dblY) << endl;
	//显式实例化
	cout << Greater(intX, intY) << endl;
	cout << Greater(dblX, dblY) << endl;
	system("pause");
	return 0;
}

//模板函数定义
template<class Ex>
Ex Greater(Ex x, Ex y)
{
	return x > y ? x : y;
}