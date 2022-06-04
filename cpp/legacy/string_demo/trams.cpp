#include <iostream>
using namespace std;

int main()
{
	//void change(int, int);
	//void change(int&, int&);
	void change(int*, int*);
	int x = 2, y = 3;
	cout << "交换前x=" << x << "y=" << y << endl;
	change(&x, &y);
	cout << "交换后x=" << x << "y=" << y << endl;
	system("pause");
	return 0;
}
/*值传递
void change(int n, int m) {
	int temp;
	temp = n;
	n = m;
	m = temp;
}*/

/*引用传递
void change(int &n, int &m) {
	int temp;
	temp = n;
	n = m;
	m = temp;
}*/

//指针传递
void change(int *n, int *m) {
	int temp;
	temp = *n;
	*n = *m;
	*m = temp;
}
