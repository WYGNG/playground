#include <iostream>

using namespace std;

class A_overload{
    virtual int fun();
    void fun(int);
    void fun(double, double);
    static int fun(char);
};

//父类
class A{
public:
    virtual int fun(int a){ return 0; }
};
//子类
class B : public A{
public:
    //重写,一般加override可以确保是重写父类的函数
    virtual int fun(int a) override{return 0;}
};

//父类
class A_hide{
public:
    void fun(int a){
		cout << "A中的fun函数" << endl;
	}
};
//子类
class B_hide : public A_hide{
public:
    //隐藏父类的fun函数
    void fun(int a){
		cout << "B中的fun函数" << endl;
	}
};

int main(){
    B_hide b;
    b.fun(2); //调用的是B中的fun函数
    b.A_hide::fun(2); //调用A中fun函数
    return 0;
}
