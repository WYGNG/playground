#include <iostream>
using namespace std;

/* �麯������̬����
 * 
 */

//����base����

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
	void disp()//������child1�ж����disp������base���disp������
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
	//�������ã�����ú�ָ�����
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

	//˵��pBase�͹ܻ���ķ�Χ�������ĸ�����ȡ����ָ�������
	pBase = &obj_child1;
	pBase->disp();
	//��Ҫ�����麯��virtual�����base��child1��child2��Ȼ��������base
	//�����û���ָ�룬���ݲ�����ͬ�����ò�ͬ����
	//ʡȥ�˶���ͬ���ܺ������鷳
	//���ڵĴ�����Է�����δ����������
	display(&obj_base);
	display(&obj_child1);
	display(&obj_child2);

	system("pause");
	return 0;
}