#include <iostream>
#include <vector>

using namespace std;

void int2str(int n, char* str) {
	char buf[20] = "";
	int i = 0;
	int temp = (n < 0) ? -n : n;

	if (str == nullptr) return;

	while (temp) {
		buf[i++] = (temp % 10) + '0';
		temp /= 10;
	}

	int len = (n < 0) ? ++i : i;

	str[i] = 0;//最后一位为停止位

	while (1) {
		i--;
		if (buf[len - i - 1] == 0) break;
		str[i] = buf[len - i - 1];
		
	}

	                                        if (i == 0) str[i] = '-';

}

int main() {


	//int nNum;
	//cin >> nNum;
	//char p[20];

	//int2str(nNum, p);

	//cout << p << endl;


	vector<int> vct;
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;
	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;

	vct.push_back(1);
	cout << vct.capacity() << endl;
	cout << vct.size() << endl;
	system("pause");






	return 0;
}