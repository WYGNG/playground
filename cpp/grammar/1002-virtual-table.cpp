#include <iostream>

using namespace std;

class A {
public:
    int a;
    virtual void read() {cout << a << " this is A's read" << endl;}
};

class B : public A {
public:
    virtual void read() {cout << a << " this is B's read" << endl;}
};



int main() {
    //find virtual tab
    A a1, a2;
    B b1, b2;
    cout << "does diff obj using one virtual tab ptr" << endl;
    typedef void (A::*classfunptr)(void);
    classfunptr readptr = &A::read;
    cout << "call A::read by using readptr " << endl;
    (a1.*readptr)();
    classfunptr ** vptr1 = reinterpret_cast<classfunptr **>(&a1);
    classfunptr ** vptr2 = reinterpret_cast<classfunptr **>(&a2);
    classfunptr ** vptrb1 = reinterpret_cast<classfunptr **>(&b1);
    classfunptr ** vptrb2 = reinterpret_cast<classfunptr **>(&b2);
    cout << "a1 addr " << vptr1 << endl;
    cout << "a2 addr " << vptr2 << endl;
    cout << "b1 addr " << vptrb1 << endl;
    cout << "b2 addr " << vptrb2 << endl;
    cout << "vptr1 val " << vptr1[0] << endl;
    cout << "vptr2 val " << vptr2[0] << endl;
    cout << "vptrb1 val " << vptrb1[0] << endl;
    cout << "vptrb2 val " << vptrb2[0] << endl;
    cout << "vtab1 val " << vptr1[0][0] << endl;
    cout << "vtab2 val " << vptr2[0][0] << endl;
    cout << "vtabb1 val " << vptrb1[0][0] << endl;
    cout << "vtabb2 val " << vptrb2[0][0] << endl;
    cout << "call the addr" << endl;
    // readptr = vptr1[0][0];
    // (a1.*readptr)();    //segmentation fault
    return 0;
}