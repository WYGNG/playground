#include <iostream>

using namespace std;

class Base1 {
public:
    Base1(int num) : num_1(num) {};
    virtual void foo1() {cout << "base1::foo1 " << num_1 << endl;}
    virtual void foo2() {cout << "base1::foo2 " << num_1 << endl;}
    virtual void foo3() {cout << "base1::foo3 " << num_1 << endl;}
private:
    int num_1;
};

class Base2 {
public:
    Base2(int num) : num_2(num) {};
    virtual void foo1() {cout << "base2::foo1 " << num_2 << endl;}
    virtual void foo2() {cout << "base2::foo2 " << num_2 << endl;}
    virtual void foo3() {cout << "base2::foo3 " << num_2 << endl;}
private:
    int num_2;
};

class Base3 {
public:
    Base3(int num) : num_3(num) {};
    virtual void foo1() {cout << "base3::foo1 " << num_3 << endl;}
    virtual void foo2() {cout << "base3::foo2 " << num_3 << endl;}
    virtual void foo3() {cout << "base3::foo3 " << num_3 << endl;}
private:
    int num_3;
};

class Derived1 : public Base1 {
public:
    Derived1(int num) : Base1(num) {}
    virtual void faa1() {cout << "derived1::faa1" << endl;}
    virtual void faa2() {cout << "derived1::faa2" << endl;}
};

class Derived2 : public Base1 {
public:
    Derived2(int num) : Base1(num) {}
    virtual void foo2() {cout << "derived2::foo2" << endl;}
    virtual void fbb2() {cout << "derived2::fbb2" << endl;}
    virtual void fbb3() {cout << "derived2::fbb3" << endl;}
};

class Derived3 : public Base1, public Base2, public Base3 {
public:
    Derived3(int num_1, int num_2, int num_3) : Base1(num_1), Base2(num_2), Base3(num_3) {}
    virtual void fcc1() {cout << "derived3::fcc1" << endl;}
    virtual void fcc2() {cout << "derived3::fcc2" << endl;}
};

class Derived4 : public Base1, public Base2, public Base3 {
public:
    Derived4(int num_1, int num_2, int num_3) : Base1(num_1), Base2(num_2), Base3(num_3) {}
    virtual void foo1() {cout << "derived4::foo1" << endl;}
    virtual void foo2() {cout << "derived4::foo2" << endl;}
};


int main () {
    Base1 *pBase1 = NULL;
    Base2 *pBase2 = NULL;
    Base3 *pBase3 = NULL;

    cout << "one derived no override" << endl;
    Derived1 d1(1);
    pBase1 = &d1;
    pBase1->foo1();


    cout << "one derived with override" << endl;
    Derived2 d2(2);
    pBase1 = &d2;
    pBase1->foo2();

    cout << "mutil derived no override" << endl;
    Derived3 d3(1, 2, 3);
    pBase1 = &d3;
    pBase2 = &d3;
    pBase3 = &d3;
    pBase1->foo1();
    pBase2->foo1();
    pBase3->foo1();

    cout << "mutil derived with override" << endl;
    Derived4 d4(1, 2, 3);
    pBase1 = &d4;
    pBase2 = &d4;
    pBase3 = &d4;
    pBase1->foo1();
    pBase2->foo1();
    pBase3->foo1();
    return 0;
}