#include <iostream>
using namespace std;

///static 编译时就被创建和初始化 被类内成员共享
class computer
{
private:
	float price;
	static float total_price;
public:
	computer(const float p)
	{
		price = p;
		total_price += p;
	}

	~computer()
	{
		total_price -= price;
	}

	void print()
	{
		cout << "总价" << total_price << endl;
	}
};
//需要初始化，真正的内存分配，在静态存储区
float computer::total_price = 0;

int main()
{
	computer comp1(7000);
	cout << "购买电脑1后" << endl;
	comp1.print();
	computer comp2(4999);
	cout << "购买电脑2后" << endl;
	comp2.print();
	computer comp3(2500);
	cout << "购买电脑3后" << endl;
	comp3.print();

	comp2.~computer();
	cout << "退掉电脑2后" << endl;
	comp1.print();
	comp2.print();
	comp3.print();
	system("pause");
	return 0;
}