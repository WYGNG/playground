#include <iostream>
using namespace std;

//����ģ��
//��ʾʵ����
//��ʽʵ����

//����ģ�������
template<class Ex>
Ex Greater(Ex x, Ex y);
//��ʾʵ����
template int Greater<int>(int, int);
int main()
{
	int intX = 1, intY = 2;
	double dblX = 3.0, dblY = 2.9;
	//��ʽʵ����
	//ʵ��Ϊint������int��ģ�庯�������Եڶ����������
	cout << Greater(intX, intY) << endl;
	cout << Greater(dblX, dblY) << endl;
	//��ʽʵ����
	cout << Greater(intX, intY) << endl;
	cout << Greater(dblX, dblY) << endl;
	system("pause");
	return 0;
}

//ģ�庯������
template<class Ex>
Ex Greater(Ex x, Ex y)
{
	return x > y ? x : y;
}