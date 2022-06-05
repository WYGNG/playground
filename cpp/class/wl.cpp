#include <iostream>
#include <set>
#include <vector>

using namespace std;



class Base {
public:
	virtual void fn() { cout << "base" << endl; };
};

class Sub : public Base {
public:
	void fn() { cout << "sub" << endl; };
};

void test(Base& tst) {
	tst.fn();
}




int main()
{
	Base b;
	Sub s;
	Base *bs = new Sub;



	test(b);
	test(*static_cast<Base *>(&s));
	test(*bs);
	//b.fn();
	//s.fn();

	system("pause");
	return 0;
}