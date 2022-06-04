#include <iostream>
using namespace std;

class A
{
private:
	int x;
public:
	A(int xp = 0)
	{
		x = xp;
		cout << "A的构造函数被执行" << endl;
	}
	~A()
	{
		cout << "A的析构函数被执行" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B的构造函数被执行" << endl;
	}
	~B()
	{
		cout << "B的析构函数被执行" << endl;
	}
};

class C :public A
{
private:
	int y;
	B b;
public:
	C(int xp, int yp) :A(xp), b()
	{
		y = yp;
		cout << "C的构造函数被执行" << endl;
	}
	~C()
	{
		cout << "C的析构函数被执行" << endl;
	}
};

int main()
{
	C *c = new C(1, 2);//析构函数可以在执行后自动调用
	c->~C();
	system("pause");
	return 0;
}