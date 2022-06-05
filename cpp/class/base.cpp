#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
using namespace std;

class base {
public:
	void fun() {
		cout << "this is base fun" << endl;
	};
	
private:
	static int num;
	int val;
};


class derived1 : public base {
public:
	void fun() {
		cout << "this is derived 1" << endl;
	};
};

class derived2 : public base {
public:
	void fun() {
		cout << "this is derived 2" << endl;
	};
};

class derived3 : public derived1 {
public:
	//void fun() {
	//	cout << "this is derived 3" << endl;
	//};
};

inline uint64_t n48tou64(uint8_t* buf) {
	uint64_t word1 = buf[5];
	uint64_t word2 = buf[4];
	uint64_t word3 = buf[3];
	uint64_t word4 = buf[2];
	uint64_t word5 = buf[1];
	uint64_t word6 = buf[0];
	uint64_t gid = (word6 << 40) | (word5 << 32) | (word4 << 24) | (word3 << 16) | (word2 << 8) | word1;
	return gid;
}

inline void u64ton48(uint8_t* buf, uint64_t gid) {
	buf[0] = (gid >> 40) & 0xff;
	buf[1] = (gid >> 32) & 0xff;
	buf[2] = (gid >> 24) & 0xff;
	buf[3] = (gid >> 16) & 0xff;
	buf[4] = (gid >> 8) & 0xff;
	buf[5] = gid & 0xff;
}

int main() {
	//cout << (3) % 2 << endl;
	//derived1 d1;
	//derived2 d2;
	//derived3 d3;


	//d1.fun();

	//d2.fun();

	//d3.fun();
	uint8_t data[6];

	uint64_t gid;
	
	scanf("%llx", &gid);

	u64ton48(data, gid);

	for (int i = 0; i < 6; i++) {
		printf("%02x", data[i]);
	}
	cout << endl;
	gid = n48tou64(data);

	printf("%llx", gid);

	cout << endl;


	system("pause");
	return 0;
}