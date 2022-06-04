#include <iostream>

using namespace std;

int main() {

	//const cast
	const int a = 0x6666;
	const int * cptr = &a;
	int * ptr = const_cast<int *>(cptr);
	*ptr = 0x9999;
	cout << hex << *ptr << endl;

	//static cast



	//dynamic cast
	


	//reinterpret cast

	

	system("pause");
	return 0;
}