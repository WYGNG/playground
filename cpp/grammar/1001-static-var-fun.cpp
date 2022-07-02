#include <iostream>
#include <type_traits>

using namespace std;


class A {
private:
    static int s_a;
    int a;
    const int c_a;
public:
    A() : c_a(0) {cout << "default constructor" << endl;};
    A(int c) : c_a(c) {cout << "para constructor" << endl;};
    A(const A& a) : a(a.a), c_a(a.c_a) {cout << "copy constructor" << endl;};
    A& operator=(const A& tmp) {
		//防止自赋值
		if (this == &tmp)
		{
			return *this;
		}
        this->a = tmp.a;
        cout << "assign " << endl;
		return *this;
    }

    static int s_r() {return A::s_a;};
    static void s_w(const int a) {A::s_a = a;};
    int ss_r() {return A::s_a;};
    void ss_w(const int a) {A::s_a = a;};

    

    ~A() {};
};






int main () {
    A a1, a2;

    A b1(a1);
    A b2 = a2;
    b1 = a2;


    return 0;
}
