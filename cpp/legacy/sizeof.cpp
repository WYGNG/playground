#include <iostream>


using namespace std;

int main() {

	typedef union {
		short i;
		int k[5];
		char c;
	} Mat;

	typedef struct {
		int i;
		Mat j;
		double k;
	} Like;

	//4B¶ÔÆë£¬20 + 4 + 10 + 8

	printf("size of : %d\n",sizeof(Like) + sizeof(Mat));

	system("pause");



	return 0;
}