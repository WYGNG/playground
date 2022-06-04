#include <iostream>
using namespace std;
//��ģ�壬����ջ��
//���Ͳ�����
template <class T, int num>//ģ��
class Stack
{
private:
	T sz[num];
	int point;
public:
	Stack();
	bool isEmpty();
	bool isFull();
	bool push(const T&);
	bool pop(T&);
};

template <class T, int num>
Stack<T,num>::Stack() 
{
	point = 0;
}

template <class T1, int num1>
bool Stack<T1, num1>::isEmpty()
{
	return point == 0;
}

template <class T, int num>
bool Stack<T, num>::isFull()
{
	return point == num;
}

template <class T, int num>
bool Stack<T, num>::push(const T& obt)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		sz[point] = obt;
		point++;
		return true;
	}
}

template <class T, int num>
bool Stack<T, num>::pop(T& obt)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		point--;
		obt = sz[point];
		return true;
	}
}

int main()
{
	Stack<int, 10> st;
	cout << "��ʼʱ��st�Ƿ�Ϊ��" << st.isEmpty() << endl;
	st.push(5);
	cout << "��ʱ��st�Ƿ�Ϊ��" << st.isEmpty() << endl;
	for (int i = 1; i < 10; i++)
	{
		st.push(i);
	}
	cout << "��ʱ��st�Ƿ�Ϊ��" << st.isFull() << endl;
	int rec = 0;
	while (st.pop(rec))
	{
		cout << rec << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

