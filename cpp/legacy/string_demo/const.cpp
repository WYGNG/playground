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
	//const��Ա�����޷��޸����ݳ�Ա
	void print_c() const
	{
		cout << x << endl;
		cout << y << endl;

	}
	void print() const//�����ں����ڵ��÷�const��Ա����
	{
		//x = 5;//��ͼ�޸�x����������������
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