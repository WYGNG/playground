#include <iostream>
using namespace std;

//�Զ��洢����̬�洢�� ��̬�洢
//

/*
�Զ��洢��ջ�洢
�����βΣ��ڲ������������ṹ�����
*/
/*
int add(int m, int n)
{
	//z 
	int z = m + n;
	return z;
}

int add(int m, int n)
{
	if (m != 0)
	{
		//���������ڴ������
		int z = m + n;
	}
	//return z;
}*/
/*
��̬�洢��������Ԥ���䣻���ô洢
extern�ؼ��֣�ȫ�ֱ������ⲿ���� 
���������� �� ����������


*/


int main()
{
	//����������
	extern int num1;
	cout << num1 << endl;
	//��������
	void change();

	change();
	cout << num1 << endl;

	system("pause");
	return 0;
}

int num1;

void change()
{
	num1 += 3;
}