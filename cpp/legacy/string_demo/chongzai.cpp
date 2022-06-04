#include <iostream>
using namespace std;
//重载

//覆盖：派生类的成员函数覆盖基类中的同名函数
//要求两个函数参数个数类型相同，基类函数必须是虚函数

//隐藏: 派生类函数与基类函数参数相同时，基类函数不是虚函数，
//参数不同时，不管基类函数是否是虚函数都会被屏蔽


/*重载
class A
{
	//.............
	//重载关系的三个函数
	virtual int fun();
	void fun(int);
	void fun(double, double);
	//...............
};
*/

//覆盖,更小范围重名覆盖原理,派生类范围更小
/*class A
{
	//  
	virtual void fun1(int, int);
	virtual int fun2(char *);
	//
};

class B:public A
{
	void fun1(int, int);
};

class C :public B
{
	//..
	int fun2(char *);
	//..
};*/

class A
{
public:
	void fun(int xp)
	{
		cout << xp << endl;
	}
};

class B :public A
{
public:
	void fun(char *s)
	{
		cout << s << endl;
	}
	void fun(int xp)//本来被覆盖了，这里直接调用
	{
		A::fun(xp);
	}
};

int main()
{
	B obB;
	obB.fun('a');
	obB.fun(2);
	system("pause");
	return 0;
}