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
		cout << "A�Ĺ��캯����ִ��" << endl;
	}
	~A()
	{
		cout << "A������������ִ��" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B�Ĺ��캯����ִ��" << endl;
	}
	~B()
	{
		cout << "B������������ִ��" << endl;
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
		cout << "C�Ĺ��캯����ִ��" << endl;
	}
	~C()
	{
		cout << "C������������ִ��" << endl;
	}
};

int main()
{
	C *c = new C(1, 2);//��������������ִ�к��Զ�����
	c->~C();
	system("pause");
	return 0;
}