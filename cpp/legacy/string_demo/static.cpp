#include <iostream>
using namespace std;

///static ����ʱ�ͱ������ͳ�ʼ�� �����ڳ�Ա����
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
		cout << "�ܼ�" << total_price << endl;
	}
};
//��Ҫ��ʼ�����������ڴ���䣬�ھ�̬�洢��
float computer::total_price = 0;

int main()
{
	computer comp1(7000);
	cout << "�������1��" << endl;
	comp1.print();
	computer comp2(4999);
	cout << "�������2��" << endl;
	comp2.print();
	computer comp3(2500);
	cout << "�������3��" << endl;
	comp3.print();

	comp2.~computer();
	cout << "�˵�����2��" << endl;
	comp1.print();
	comp2.print();
	comp3.print();
	system("pause");
	return 0;
}