#include <iostream>
using namespace std;

int main()
{
	//void change(int, int);
	//void change(int&, int&);
	void change(int*, int*);
	int x = 2, y = 3;
	cout << "����ǰx=" << x << "y=" << y << endl;
	change(&x, &y);
	cout << "������x=" << x << "y=" << y << endl;
	system("pause");
	return 0;
}
/*ֵ����
void change(int n, int m) {
	int temp;
	temp = n;
	n = m;
	m = temp;
}*/

/*���ô���
void change(int &n, int &m) {
	int temp;
	temp = n;
	n = m;
	m = temp;
}*/

//ָ�봫��
void change(int *n, int *m) {
	int temp;
	temp = *n;
	*n = *m;
	*m = temp;
}
