#include <iostream>
using namespace std;
//����

//���ǣ�������ĳ�Ա�������ǻ����е�ͬ������
//Ҫ������������������������ͬ�����ຯ���������麯��

//����: �����ຯ������ຯ��������ͬʱ�����ຯ�������麯����
//������ͬʱ�����ܻ��ຯ���Ƿ����麯�����ᱻ����


/*����
class A
{
	//.............
	//���ع�ϵ����������
	virtual int fun();
	void fun(int);
	void fun(double, double);
	//...............
};
*/

//����,��С��Χ��������ԭ��,�����෶Χ��С
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
	void fun(int xp)//�����������ˣ�����ֱ�ӵ���
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