#include <iostream>
using namespace std;

/* 虚函数：动态连编
 * 
 */

//基类base定义

class base
{
public:
	virtual void disp()
	{
		cout << "hello" << endl;
	}
};

class child1 :public base
{
public:
	void disp()//派生类child1中定义的disp函数将base类的disp隐藏了
	{
		cout << "hello,child1" << endl;
	}
};

class child2 :public base
{
public:
	void disp()
	{
		cout << "hello,child2" << endl;
	}
};

void display(base *pb)
{
	pb->disp();
}

int main()
{
	//正常调用，点调用和指针调用
	base *pBase = NULL, obj_base;
	obj_base.disp();
	pBase = &obj_base;
	pBase->disp();

	child1 *pchild1 = NULL, obj_child1;
	obj_child1.disp();
	pchild1 = &obj_child1;
	pchild1->disp();

	child2 *pchild2 = NULL, obj_child2;
	obj_child2.disp();
	pchild2 = &obj_child2;
	pchild2->disp();

	//说明pBase就管基类的范围，访问哪个对象取决于指针的类型
	pBase = &obj_child1;
	pBase->disp();
	//需要引入虚函数virtual就输出base，child1，child2不然就是三个base
	//可以用基类指针，根据参数不同，调用不同函数
	//省去了定义同功能函数的麻烦
	//现在的代码可以服务于未来的派生类
	display(&obj_base);
	display(&obj_child1);
	display(&obj_child2);

	system("pause");
	return 0;
}