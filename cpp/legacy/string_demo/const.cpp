#include <iostream>
using namespace std;

class point
{
	int x;
	int y;
public:
	point(int xp = 0, int yp = 0)
	{
		x = xp;
		y = yp;
	}
	//const成员函数无法修改数据成员
	void print_c() const
	{
		cout << x << endl;
		cout << y << endl;

	}
	void print() const//不能在函数内调用非const成员函数
	{
		//x = 5;//试图修改x，引发编译器报错
		cout << "x=:" << x << "y=" << y << endl;
	}
};

int main()
{
	point pt;
	pt.print();
	system("pause");
	return 0;
}