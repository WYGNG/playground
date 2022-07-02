#include <iostream>

using namespace std;

class A
{
public:
    friend void set_show(int x, A &a);      //该函数是友元函数的声明
private:
    int data;
};

void set_show(int x, A &a)  //友元函数定义，为了访问类A中的成员
{
    a.data = x;
    cout << a.data << endl;
}


class B
{
public:
   friend class C;                         //这是友元类的声明
private:
   int data;
};

class C             //友元类定义，为了访问类A中的成员
{
public:
   void set_show(int x, B &a) { a.data = x; cout<<a.data<<endl;}
};

int main(void)
{
   class B b;
   class C c;

   c.set_show(1, b);

    class A a;

    set_show(1, a);

    return 0;
}
